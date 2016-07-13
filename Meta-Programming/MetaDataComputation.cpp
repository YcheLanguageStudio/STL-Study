//
// Created by cheyulin on 7/13/16.
//

#include "MetaFunctionTool.h"
#include "assert.h"
#include "boost/type_traits.hpp"

using namespace boost;

void AssertComputation1() {
    mp_data mp_exec(add_const<int>) metadata1;  //添加const 修饰
    assert(mp_eval(is_const<metadata1>));
    assert((is_same<metadata1, int const>::value));
    assert((is_same<metadata1, const int>::value));

    mp_data mp_exec(add_pointer<double>) metadata2;
    assert(mp_eval(is_pointer<metadata2>));
    assert((is_same<metadata2, double *>::value));

    mp_data mp_exec(add_reference<metadata2>) metadata3;
    assert(mp_eval(is_reference<metadata3>));
    assert((is_same<metadata3, double *&>::value));

    mp_data mp_exec(add_lvalue_reference<void>) metadata4; //为void添加左引用
    assert(mp_eval(is_void<metadata4>)); //因为void 不是对象类型所以无变化
}

void AssertComputation2() {
    mp_data int const **&metadata1;
    mp_data mp_exec(remove_pointer<metadata1>) metadata2; //移除指针，但是因为是引用所以不变
    assert((is_same<metadata1, metadata2>::value));

    mp_data mp_exec(remove_reference<metadata2>) metadata3; //移除引用
    assert(mp_eval(is_pointer<metadata3>));  //int const **是指针类型
    assert((is_same<metadata3, int const **>::value));

    mp_data mp_exec(remove_pointer<mp_exec(remove_pointer<metadata3>)>) metadata4; //连续移除两次
    assert(mp_eval(is_const<metadata4>)); //int const
    assert(mp_eval(is_integral<metadata4>));
    assert((is_same<metadata4, int const>::value));

    mp_data mp_exec(remove_const<metadata4>) metadata5;
    assert((is_same<metadata5, int>::value));
}

int main() {
    AssertComputation1();
    AssertComputation2();
}