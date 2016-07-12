//
// Created by cheyulin on 7/12/16.
//

#include <iostream>
#include <cstddef>
using namespace std;

class alloc{

};

template<class T, class Alloc=alloc, size_t BufSiz=0>
class deque{
public:
    deque(){
        cout << "deque"<<endl;
    }
};

//根据前一个参数值，设定下一个参数Sequence默认为deque<T>
template <class T, class Sequence=deque<T>>
class stack{
public:
    stack(){
        cout <<"stack"<<endl;
    }

private:
    Sequence c;
};

int main(){
    stack<int> x;
}