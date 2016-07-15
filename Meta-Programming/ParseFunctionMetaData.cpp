//
// Created by cheyulin on 7/15/16.
//

//因为function_traits<>不是标准元函数，所以不能使用宏“伪关键字”来调用，
//必须使用域操作符号直接写出内部类型定义哦
#include "boost/type_traits.hpp"
#include "assert.h"
#include <iostream>
#include "MetaFunctionTool.h"

using namespace boost;

int main() {
    mp_data void(metadata1)(int, std::string);  //注意函数类型的定义方式
    assert(mp_eval(is_function<metadata1>));

    const size_t n = function_traits<metadata1>::arity;
    assert((n == 2));

    mp_data function_traits<metadata1>::result_type rtype;
    assert(is_void<rtype>::value);

    mp_data function_traits<metadata1>::arg2_type a2type;
    assert((is_same<a2type,std::string>::value));
}