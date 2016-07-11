//
// Created by cheyulin on 7/11/16.
//
#include <iostream>
#include <assert.h>
#include <boost/type_traits.hpp>

using namespace std;

template<typename T1, typename T2>
struct select1st {
    typedef T1 type;
};

template<typename T1, typename T2>
struct forward : select1st<T2, T1> { //元函数转发，使用struct默认的public继承 参数位置变动
};

//等同于以下的写法
template<typename T1, typename T2>
struct forward2 {                                    //元函数，不使用转发
    typedef typename select1st<T2, T1>::type type;   //调用元函数计算
};

int main() {
    typedef int param1;
    typedef long param2;
    assert((boost::is_same<forward2<param1, param2>::type, param2>::value));
}
