# Simple spinlock mutex in C++

This is our attempt to build a simple spinlock struct, exposing a lock , a
try_lock , and an unlock method. We test it using a std::lock_guard<SpinLock> 
in Josh's Lospinoso goat rodeo example (by the way, C++ crash course is a great book).

### maintainer
angelos plastropoulos