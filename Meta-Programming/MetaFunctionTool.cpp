//
// Created by cheyulin on 7/11/16.
//

#include <boost/type_traits/is_same.hpp>
#include "MetaFunctionTool.h"

//操作static 值的元函数
mp_arglist<int L, int R>
mp_function static_min {
    BOOST_STATIC_CONSTANT(int, value = (L < R) ? L : R);
};


//操作类型的元函数
mp_arglist<mp_arg T>            //单参数元函数
mp_function demo_func{          //非pointer时候返回 const T*
    mp_return(const T*);
};

//specialization
mp_arglist<mp_arg T>
mp_function demo_func<T*>{  //对T* pointer 情况进行特化
    mp_return(const T);     //返回const T
    //using type = const T 由编译器来推导
};

int main() {
    assert((static_min<10, 20>::value == 10));
    assert((boost::is_same<mp_exec(demo_func<int>),const int*>::value));
    assert((boost::is_same<mp_exec(demo_func<int*>),const int>::value));
}