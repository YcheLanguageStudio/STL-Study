//
// Created by cheyulin on 7/17/16.
//
#include <boost/type_traits.hpp>
#include <iostream>
using namespace boost;

//print和print2都是enable_if应用于模板函数的demo

//代码中enable_if作为函数print的缺省值出现，生命了一个无名函数指针(...::type*)，默认值是空指针
//这样编译器进行模板实例化时候，如果T不是整数，呢个么enable_if<>将不会返回任何类型，
//导致模板实例化失败，从而使得这个print()被禁用
template <typename T>
T print(T x, typename enable_if<is_integral<T>>::type* =0){
    std::cout << "int:" << x <<std::endl;
    return x;
};

//enable_if返回值用法
template <typename T>
typename enable_if<is_integral<T>, promote<T>>::type
print2(T x){
    std::cout << "ret int:" << x <<std::endl;
};

int main(){
    int i=1;
    int j= print(i);

    //如果print和print2都命名相同就会ambiguous
    auto k = print2(i);
//    如果没有可匹配的剩余函数则下面代码就会编译时候报错
//    double d=1;
//    print(d);
}