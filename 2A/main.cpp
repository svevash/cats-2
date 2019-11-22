#include <iostream>
#include <vector>

class PageAllocator {
    const std::uint64_t page_size_;
    std::vector<void*> pages_;

public:
    PageAllocator(std::uint64_t page_size) : page_size_(page_size) {
    }

    ~PageAllocator() {
        for (void* page : pages_)
            ::operator delete(page);
    }

    void* Allocate() {
        void* page = ::operator new(page_size_);
        pages_.push_back(page);
        return page;
    }

    std::uint64_t Allocated() const noexcept {
        return pages_.size();
    }
};

#include <vector>
template<typename Tp>
class FixedAllocator {
  PageAllocator page_allocator_;
  std::vector<Tp*> freemem_, usedmem_;
  const std::uint64_t pages;

 public:
  explicit FixedAllocator(std::uint64_t page_size) :
  page_allocator_(page_size * sizeof(Tp)),
  freemem_(),  usedmem_(), pages(page_size){
      Tp* p = reinterpret_cast<Tp*>(page_allocator_.Allocate());
      freemem_.push_back(p);
      for (std::uint64_t i = 0; i < page_size - 1; i++) {
          p++;
          freemem_.push_back(p);
      }
  }

  Tp* Allocate() {
      Tp* p;
      if (freemem_.empty()) {
          Tp* pp = reinterpret_cast<Tp*>(page_allocator_.Allocate());
          freemem_.push_back(pp);
          for (std::uint64_t i = 0; i < pages - 1; i++) {
              pp++;
              freemem_.push_back(pp);
          }
      }

      p = freemem_[freemem_.size() - 1];
      freemem_.pop_back();
      usedmem_.push_back(p);
      return p;
  }

  void Deallocate(Tp* p) {
      freemem_.push_back(p);
      for (std::uint64_t i = 0; i < usedmem_.size(); i++) {
          if (usedmem_[i] == p) {
              usedmem_.erase(usedmem_.begin() + i);
          }
      }
  }

  const PageAllocator& InnerAllocator() const noexcept {
      return page_allocator_;
  }
};

int main()
{
    srand(666);

    const auto require_allocs = [](std::uint64_t expected, std::uint64_t actual) -> void {
        if (expected == actual)
            return;
        std::cout << "Invalid count of page allocations" << std::endl;
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "You have: " << actual << std::endl;
        std::exit(0);
    };

    {
        FixedAllocator<int> a(1);
        auto p1 = a.Allocate();
        auto p2 = a.Allocate();
        a.Deallocate(p1);
        a.Deallocate(p2);
        p1 = a.Allocate();
        p2 = a.Allocate();
        require_allocs(2, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(10);
        for (int i = 0; i < 10; ++i)
            a.Allocate();
        require_allocs(1, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(100);
        for (int i = 0; i < 50; ++i)
            a.Deallocate(a.Allocate());
        require_allocs(1, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(1);
        for (int i = 0; i < 5; ++i)
            a.Deallocate(a.Allocate());
        require_allocs(1, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(1);
        for (int i = 0; i < 50; ++i)
        {
            a.Allocate();
            a.Deallocate(a.Allocate());
        }
        require_allocs(51, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(100);
        for (int i = 0; i < 500; ++i)
        {
            a.Allocate();
            a.Deallocate(a.Allocate());
        }
        require_allocs(6, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(100);
        for (int i = 0; i < 1000; ++i)
        {
            a.Allocate();
            a.Deallocate(a.Allocate());
        }
        require_allocs(11, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<std::string> a(1000000);
        for (int i = 0; i < 1000000; ++i)
        {
            a.Allocate();
            a.Deallocate(a.Allocate());
        }
        require_allocs(2, a.InnerAllocator().Allocated());
    }

    {
        FixedAllocator<char> a(100);
        std::vector<char*> store;
        for (int i = 0; i < 100; ++i)
            store.push_back(a.Allocate());
        for (int i = 0; i < 10000; ++i)
        {
            const int rnd = rand() % 100;
            a.Deallocate(store[rnd]);
            if (a.Allocate() != store[rnd])
            {
                std::cout << "Invalid allocation result" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "GOOD" << std::endl;
    return 0;
}