#include <iostream>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <utility>

template <typename T>
class Queue {
 public:
  Queue() : queue_(), mutex_() {}
  ~Queue() = default;
  T Pop() {
      mutex_.lock();
      auto val = std::forward<T>(queue_.front());
      queue_.pop();
      mutex_.unlock();
      return val;
  }
  size_t Size() {
      mutex_.lock();
      auto size = queue_.size();
      mutex_.unlock();
      return size;
  }
  template <typename U>
  void Push(U&& val) {
      mutex_.lock();
      queue_.push(std::forward<U>(val));
      mutex_.unlock();
  }
  template <typename... U>
  void Emplace(U&&... val) {
      mutex_.lock();
      queue_.emplace(std::forward<U>(val)...);
      mutex_.unlock();
  }
 private:
  std::queue<T> queue_;
  std::mutex mutex_;
};