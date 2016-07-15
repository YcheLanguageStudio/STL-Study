//
// Created by cheyulin on 7/15/16.
//

#include "boost/type_traits.hpp"
#include "MetaFunctionTool.h"

using namespace boost;

int main() {
    //元函数计算   int类型的整数10
    assert((integral_constant<int, 10>::value == 10));

    BOOST_STATIC_ASSERT((integral_constant<char, 0x30>::value == '0'));

    BOOST_STATIC_ASSERT((integral_constant<short, 100>::value == 100));
}