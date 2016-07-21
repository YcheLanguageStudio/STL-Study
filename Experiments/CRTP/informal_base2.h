//
// Created by cheyulin on 7/21/16.
//

#ifndef STLSTUDY_BASE2_H
#define STLSTUDY_BASE2_H

#include <iostream>

namespace yche {
    template<typename T>
    class MyTemplate {
        T *member;
    public:
        MyTemplate(T *member) : member(member) {}

    public:
        T *method() {
            member->print1();
            member->print2();
        }
        // ...
    };

}

#endif //STLSTUDY_BASE2_H
