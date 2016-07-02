//
// Created by cheyulin on 7/2/16.
//

#include <iostream>
#include <cstddef>

using namespace std;

class alloc {
};

template<class T, class Alloc=alloc, size_t BufSiz = 0>
class deque {
public:
    deque() { cout << "deque" << endl; }
};

//以下申明如果不出现或出现， GCC 都可以通过
template<class T, class Sequence>
class stack;

template<class T, class Sequence>
bool operator==(const stack<T, Sequence> &x,
                const stack<T, Sequence> &y);

template<class T, class Sequence>
bool operator<(const stack<T, Sequence> &x,
                const stack<T, Sequence> &y);

template<class T, class Sequence= deque<T>>
class stack {
    //写成这样的是可以的
    friend bool operator==<T>(const stack<T> &, const stack<T> &);

    friend bool operator< <T>(const stack<T> &, const stack<T> &);

    //写成这样也是可以的
    friend bool operator==<T>(const stack &, const stack &);

    friend bool operator< <T>(const stack &, const stack &);

    //写成这样也是可以的
    friend bool operator==<>(const stack &, const stack &);

    friend bool operator< <>(const stack &, const stack &);

    //省略<>是不可以的
    //    friend bool operator== (const stack &, const stack &);
    //    friend bool operator< (const stack &, const stack &);

public:
    stack() { cout << "stack" << endl; }

private:
    Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T,Sequence>&x, const stack<T,Sequence>&y){
     cout << "operator =="<<'\t';
};

template <class T, class Sequence>
bool operator<(const stack<T,Sequence>&x, const stack<T,Sequence>&y){
     cout << "operator <"<<'\t';
};

int main(){
    stack<int> x;
    stack<int> y;
    cout <<(x==y)<<endl;
    cout <<(x<y)<<endl;

    stack<char>  y1;
}

