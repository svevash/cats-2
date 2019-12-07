#pragma once

#include <memory>
#include "Test.h"

namespace smart_pointer {
// `exception` class definition
class exception : std::exception {
  using base_class = std::exception;
  using base_class::base_class;
};

// `SmartPointer` class declaration
template<
    typename T,
    typename Allocator
>
class SmartPointer {
  // don't remove this macro
  ENABLE_CLASS_TESTS;
 public:
  using value_type = T;

  SmartPointer(value_type *p = nullptr) {
      if (p == nullptr) {
          core = nullptr;
      } else {
          core = new Core;
          core->count_pointers_ = 1;
          core->pointer_ = p;
      }
  }

  // copy constructor
  SmartPointer(const SmartPointer &smartPointer) {
      if (smartPointer.core == nullptr) {
          core = nullptr;
      } else {
          smartPointer.core->count_pointers_++;
          core = new Core;
          core->count_pointers_ = smartPointer.core->count_pointers_;
          core->pointer_ = smartPointer.core->pointer_;
      }
  }

  // move constructor
  SmartPointer(SmartPointer &&smartPointer) {
      if (smartPointer.core == nullptr) {
          core = nullptr;
      } else {
          core = new Core;
          core->count_pointers_ = smartPointer.core->count_pointers_;
          core->pointer_ = smartPointer.core->pointer_;
      }
  }

  // copy assigment
  SmartPointer &operator=(const SmartPointer &smartPointer) {
      if (smartPointer.core == nullptr) {
          core = nullptr;
      } else {
          smartPointer.core->count_pointers_++;
          core = new Core;
          core->count_pointers_ = smartPointer.core->count_pointers_;
          core->pointer_ = smartPointer.core->pointer_;
      }
      return *this;
  }

  // move assigment
  SmartPointer &operator=(SmartPointer &&smartPointer) {
      if (smartPointer.core == nullptr) {
          core = nullptr;
      } else {
          core = new Core;
          core->count_pointers_ = smartPointer.core->count_pointers_;
          core->pointer_ = smartPointer.core->pointer_;
      }
      return *this;
  }

  //
  SmartPointer &operator=(value_type *p) {
      if (p == nullptr) {
          core = nullptr;
      } else {
          core = new Core;
          core->count_pointers_ = 1;
          core->pointer_ = p;
      }
      return *this;
  }

  ~SmartPointer() {
      if (core != nullptr) {
          core->count_pointers_--;
      }
  }

  // return reference to the object of class/type T
  // if SmartPointer contains nullptr throw `SmartPointer::exception`
  value_type &operator*() {
      if (core == nullptr) {
          throw smart_pointer::exception();
      }
      return *core->pointer_;
  }

  const value_type &operator*() const {
      if (core == nullptr) {
          throw smart_pointer::exception();
      }
      return *core->pointer_;
  }

  // return pointer to the object of class/type T
  value_type *operator->() const {
      if (core == nullptr) {
          return nullptr;
      }
      return core->pointer_;
  }

  value_type *get() const {
      if (core == nullptr) {
          return nullptr;
      }
      return core->pointer_;
  }

  // if pointer == nullptr => return false
  operator bool() const {
      return core != nullptr;
  }

  // if pointers points to the same address or both null => true
  template<typename U, typename AnotherAllocator>
  bool operator==(const SmartPointer<U, AnotherAllocator> & smartPointer) const {
      if (smartPointer.get() == nullptr && this->get() == nullptr) {
          return true;
      }
      return static_cast<void*>(smartPointer.get()) == static_cast<void*>(this->get());
  }

  // if pointers points to the same address or both null => false
  template<typename U, typename AnotherAllocator>
  bool operator!=(const SmartPointer<U, AnotherAllocator> & smartPointer) const {
      if (smartPointer.get() == nullptr && this->get() == nullptr) {
          return false;
      } else if (smartPointer.get() == nullptr || this->get() == nullptr) {
          return true;
      }
      return static_cast<void*>(smartPointer.get()) != static_cast<void*>(this->get());
  }

  // if smart pointer contains non-nullptr => return count owners
  // if smart pointer contains nullptr => return 0
  std::size_t count_owners() const {
      if (core == nullptr) {
          return 0;
      }
      return core->count_pointers_;
  }

 private:
  class Core {
   public:
    std::size_t count_pointers_;
    value_type* pointer_;
    ~Core() {
        delete pointer_;
    }
  };
  Core *core;
};
}