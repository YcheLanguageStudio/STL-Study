//
// Created by cheyulin on 7/10/16.
//

#define some_int 1

struct some_type;
//编写元函数就像是编写一个普通的运行函数，但形式上确是一个模板类
template<typename arg1, typename arg2> // 元函数参数列表
struct meta_function {
    typedef some_type type;  //type 是 元数据  值为 some_type
    //using type = some_type
    static int const value = some_int;
};

#include <boost/config.hpp>
#include <iostream>

template<int N, int M>  //两个整数元数据
struct meta_function1 {
    BOOST_STATIC_CONSTANT(int, value = N + M); //编译器计算整数之和
};

int main() {
    using namespace std;
    cout << meta_function1<10, 10>::value << endl;
}