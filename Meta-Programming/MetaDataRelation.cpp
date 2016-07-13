//
// Created by cheyulin on 7/13/16.
//

#include "MetaFunctionTool.h"
#include <iostream>
#include "boost/type_traits.hpp"
#include <assert.h>

mp_data int meta_data1;
mp_data short meta_data2;

using namespace boost;

int main() {
    //四个比较元数据关系的元函数
    assert((is_same<int, meta_data1>::value));
    assert((is_convertible<meta_data2, int>::value)); //short 可转化为 int
    assert((is_base_of<std::string, std::string>::value));  //string  是自己的基类
    assert((is_base_of<std::ios_base, std::ostream>::value)); //IO 流继承体系

    assert((!is_virtual_base_of<std::ios_base, std::ostream>::value));
    assert((is_virtual_base_of<std::basic_ios<char>, std::ostream>::value));
}