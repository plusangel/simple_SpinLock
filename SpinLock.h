//
// Created by angelos on 11/03/2020.
// Credits to vovaprog from github (https://github.com/vovaprog)
//

#ifndef RODEO_RACE_SPINLOCK_H
#define RODEO_RACE_SPINLOCK_H
#include <atomic>

struct SpinLock {
  SpinLock() { flag.clear(); }

  SpinLock(const SpinLock &s) = delete;
  SpinLock(SpinLock &&s) = delete;
  SpinLock &operator=(const SpinLock &s) = delete;
  SpinLock &operator=(SpinLock &&s) = delete;

  void lock() {
    while (flag.test_and_set(std::memory_order_acquire))
      ;
  }

  bool try_lock() { return !flag.test_and_set(std::memory_order_acquire); }

  void unlock() { flag.clear(std::memory_order_release); }

private:
  std::atomic_flag flag{};
};

#endif // RODEO_RACE_SPINLOCK_H
