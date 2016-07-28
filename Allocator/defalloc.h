#ifndef DEFALLOC_H
#define DEFALLOC_H

#include <algobase.h>
#include <iostream.h>
#include <limits.h>
#include <new.h>
#include <stddef.h>
#include <stdlib.h>

template <class T> inline T *allocate(ptrdiff_t size, T *) {
  set_new_handler(0);
  T *tmp = (T *)(::operator new((size_t)(size * sizeof(T))));
  if (tmp == 0) {
    cerr << "out of memeory" << endl;
  }

  template <class T> inline void deallocate(T * buffer) {
    ::operator delete(buffer);
  }

  template <class T> class allocator {
  public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
  }

  pointer
  allocate(size_type n) {
    return ::allocate((difference_type)n, (pointer)0);
  }

  void deallocate(pointer p) { ::deallocate(p); }

  pointer address(reference x{
    return (pointer)&x;
  }

  const_pointer const_address(const_reference x){
    return (const_pointer)&x;
  }

 size_type init_page_size(){
    return max(size_type(1), size_type(4096 / sizeof(T)));
 }
 size_type max_size() const{
    return max(size_type(1), size_type(UNIT_MAX / sizeof(T)));
 }
}

// Specialization
template <> class allocator<void> {
public:
  typedef void *pointer;
}

#endif
