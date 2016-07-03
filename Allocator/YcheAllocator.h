//
// Created by cheyulin on 7/3/16.
//

#ifndef STLSTUDY_JJALLOCATOR_H
#define STLSTUDY_JJALLOCATOR_H

#include <new>  //for placement new
#include <cstddef> // for ptrdiff_t, size_T
#include <cstdlib> // for exit
#include <climits> // for UNIT_MAX
#include <iostream>  // for cerr
#include <limits>

using namespace std;
namespace yche {
    template<class T>
    inline T *_allocate(ptrdiff_t size, T *) {
        set_new_handler(0);
        T *tmp = (T *) (::operator new((size_t) (size * sizeof(T))));
        if (tmp == 0) {
            cerr << "out of memory " << endl;
        }
        return tmp;
    }

    template<class T>
    inline void _deallocate(T *buffer) {
        ::operator delete(buffer);
    }

    template<class T1, class T2>
    inline void _construct(T1 *p, const T2 &value) {
        new(p) T1(value); //placement new , invoke ctor of T1
    };

    template<class T>
    inline void _destroy(T *ptr) {
        ptr->~T();
    }

    template<class T>
    class allocator {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        //rebind allocator of type U
        template<class U>
        struct bind {
            typedef allocator<U> other;
        };

        //hint userd for lcoality ref. [Austern],p189
        pointer allocate(size_type n, const void *hint = 0) {
            return _allocate((difference_type) n, (pointer) 0);
        }

        void deallocate(pointer p, size_type n) {
            _deallocate(p);
        }

        void construct(pointer p, const T &value) {
            _construct(p, value);
        }

        void destory(pointer p) {
            _destroy(p);
        }

        pointer address(reference x) {
            return (pointer) &x;
        }

        const_pointer const_address(const_reference x) {
            return (const_pointer) &x;
        }

        size_type max_size() const {
            return size_type(numeric_limits<T>::max() / sizeof(T));
        }
    };

};

#endif //STLSTUDY_JJALLOCATOR_H