//
// Created by cheyulin on 7/21/16.
//

#ifndef STLSTUDY_FORMAL_BASE_H_H
#define STLSTUDY_FORMAL_BASE_H_H

#include <iostream>
namespace yche{
    template <class T>
    struct Base
    {
        void template_method(){
            interface();
            interface();
        }

        void interface()
        {
            // ...
            static_cast<T*>(this)->implementation();
            // ...
        }

        static void static_func()
        {
            // ...
            T::static_sub_func();
            // ...
        }
    };
}

#endif //STLSTUDY_FORMAL_BASE_H_H
