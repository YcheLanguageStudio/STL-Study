//
// Created by cheyulin on 7/11/16.
//

#include <boost/type_traits.hpp>
#include "MetaFunctionTool.h"
#include <vector>
using namespace boost;


int main() {
//元函数类别1
    assert(mp_eval(is_integral<const char>));    //const 修饰
    assert(mp_eval(is_integral<unsigned long>));    //unsigned 修饰
    assert(!mp_eval(is_integral<int *>));

    assert(mp_eval(is_float<double>));            //double是浮点类型
    assert(mp_eval(is_floating_point<float>));
    assert(!mp_eval(is_floating_point<int *>));

    assert(mp_eval(is_void<void>));
    assert(!mp_eval(is_void<void*>));       //void *指针类型不是void

    assert(mp_eval(is_array<double[]>));
    assert(mp_eval(is_array<int[2][3]>));

    assert(mp_eval(is_class<struct dummy>));  //空类
    assert(mp_eval(is_class<std::vector<int>>));

    assert(mp_eval(is_complex<std::complex<double>>));

    assert(mp_eval(is_pointer<int*>));
    assert(mp_eval(is_pointer<int(*) (int)>)); //函数指针    e.g int test(int input)

    assert(mp_eval(is_function<void (int,double)>));//函数类型

    typedef float& float_ref;
    assert(mp_eval(is_lvalue_reference<float_ref >));
    assert(mp_eval(is_lvalue_reference<float_ref &>));  //左引用还是左引用
    assert(mp_eval(is_lvalue_reference<float_ref &&>)); //右引用类型不变
    assert(mp_eval(is_rvalue_reference<float &&>));     //右值引用

    struct dummy{
        int x;
        double y;
        void func(int hello){}
    };

    assert(mp_eval(is_member_object_pointer<int(dummy::*)>));
    assert(mp_eval(is_member_object_pointer<double(dummy::*)>));
    assert(mp_eval(is_member_function_pointer<void(dummy::*)(int)>));

    //元数据类别2
}