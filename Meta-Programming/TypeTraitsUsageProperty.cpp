//
// Created by cheyulin on 7/11/16.
//

#include <boost/type_traits.hpp>
#include <vector>
#include "MetaFunctionTool.h"

using namespace boost;

int main() {
    //元数据属性1
    assert(!mp_eval(is_pod<std::string>)); //标准字符串不是pod类型
    assert(mp_eval(is_empty<std::plus<int>>));//函数对象是空类
    assert(mp_eval(is_polymorphic<std::iostream>)); //标准流是多态的

    //验证各个类型字节对齐
    assert(mp_eval(alignment_of<char>) == 1);
    assert(mp_eval(alignment_of<std::string>)==8); // 64bis sys 8字节对齐
    assert(mp_eval(alignment_of<std::vector<int>>)==8);


    //元数据属性2
    //标准字符串的构造函数和拷贝构造函数可能会抛出异常
    assert(mp_eval(has_nothrow_constructor<std::string>));  //构造函数不会抛出异常
    assert(!mp_eval(has_nothrow_copy<std::string>));

    //标准字符串的转移构造函数不会抛出异常
    assert(mp_eval(is_nothrow_move_constructible<std::string>));
    assert(!mp_eval(has_trivial_move_constructor<std::string>));

    //元数据属性3 检查是否重载了某些操作符
    assert(mp_eval(has_greater<int>));
    assert(mp_eval(has_less<int>));
    assert(mp_eval(has_equal_to<int>));

    assert(mp_eval(has_greater<std::string>));
    assert(mp_eval(has_equal_to<std::string>));
    assert(!mp_eval(has_minus<std::string>));

    assert(mp_eval(has_pre_increment<std::string::iterator>));

}