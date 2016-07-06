//
// Created by cheyulin on 7/6/16.
//

#include <iostream>

using namespace std;

template <typename T>
class testClass{
public :
    static int _data;
};

//为static int members 配置内存  设置初始值
//Need Specialization
template<>
int testClass<int>::_data =1;

template<>
int testClass<char>::_data =2;

template <typename T>
class testClass2{
public :
    static T _data;
};

template<>
int testClass2<int>::_data=3;

template<>
char testClass2<char>::_data='c';

int main(){
    cout <<testClass<int>::_data <<endl;
    cout <<testClass<char>::_data <<endl;

    testClass<int> obji1, obji2;
    testClass<char> objc1,objc2;

    cout<< obji1._data<<endl;
    cout<< obji2._data<<endl;
    cout<< objc1._data<<endl;
    cout<< objc2._data<<endl;

    cout <<endl;
    cout <<testClass2<int>::_data<<endl;
    cout <<testClass2<char>::_data<<endl;
}