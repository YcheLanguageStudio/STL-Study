

#ifndef STLSTUDY_BASE_H
#define STLSTUDY_BASE_H

#include <iostream>

namespace yche {
    template<typename T>
    class MyTemplate {
        T *member;
        void print1();
        void print2();
    public:
        T *method() {
            member->print1();
            member->print2();
        }
        // ...
    };
}

#endif