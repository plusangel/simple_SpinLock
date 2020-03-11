#include "SpinLock.h"
#include <future>
#include <iostream>
#include <mutex>

void goat_rodeo() {
  const size_t iterations{1'000'000};
  int tin_cans_available{};
  SpinLock tin_can_mutex;

  auto eat_cans = std::async(std::launch::async, [&] {
    for (size_t i{}; i < iterations; i++) {
      std::lock_guard<SpinLock> guard{tin_can_mutex};
      tin_cans_available--;
    }
  });

  auto deposit_cans = std::async(std::launch::async, [&] {
    for (size_t i{}; i < iterations; i++) {
      std::lock_guard<SpinLock> guard{tin_can_mutex};
      tin_cans_available++;
    }
  });

  eat_cans.get();
  deposit_cans.get();

  std::cout << "Tin cans: " << tin_cans_available << std::endl;
}

int main() {
  goat_rodeo();
  goat_rodeo();
  goat_rodeo();

  return 0;
}