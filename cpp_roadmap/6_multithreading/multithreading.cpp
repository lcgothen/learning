#include <cstdlib>
#include <iostream>
#include <mutex>
#include <stdint.h>
#include <thread>

// we'll make 2 threads with a shared resource
class my_thread_class {
public:
  void main_execution_no_mutex() {
    std::thread dash_thread(&my_thread_class::write_to_resource, this, 20, "-");
    std::thread start_thread(&my_thread_class::write_to_resource, this, 20,
                             "*");

    dash_thread.join();
    start_thread.join();
  }

  void main_execution_with_mutex() {
    std::thread dash_thread(&my_thread_class::write_to_resource_with_mutex,
                            this, 20, "-");
    std::thread start_thread(&my_thread_class::write_to_resource_with_mutex,
                             this, 20, "*");

    dash_thread.join();
    start_thread.join();
  }

  void show_resource() {
    std::cout << "Resource: " << resource_ << std::endl;
    std::cout << "Resource size: " << resource_.size() << std::endl;
  }

  void clear_resource() { resource_.clear(); }

private:
  void write_to_resource(int n, std::string symbol) {
    {
      // std::unique_lock<std::mutex> locker(mtx);
      for (int i = 0; i < n; ++i) {
        resource_.append(symbol);
      }
    }
  }

  void write_to_resource_with_mutex(int n, std::string symbol) {
    {
      std::unique_lock<std::mutex> locker(resource_mtx_);
      for (int i = 0; i < n; ++i) {
        resource_.append(symbol);
      }
    }
  }

  std::string resource_;
  std::mutex resource_mtx_;
};

int main() {
  my_thread_class threading_class;

  // running with no mutex, we don't always get the same resource or the same
  // size
  threading_class.main_execution_no_mutex();
  threading_class.show_resource();

  threading_class.clear_resource();

  // running with a mutex is more controlled
  threading_class.main_execution_with_mutex();
  threading_class.show_resource();
}