//
// Created by cheyulin on 7/6/16.
//

#include <iostream>

using namespace std;

template <class I, class O>
struct testClass{
    testClass(){
        cout << "I,O"<<endl;
    }
};

//Class Partial Specialization
template <class T>
struct testClass<T*,T*>{
    testClass(){
        cout <<"T*,T*"<<endl;
    }
};

//Class Partial Specialization
template <class T>
struct testClass<const T*,T*>{
    testClass(){
        cout <<"const T*,T*"<<endl;
    }
};

int main(){
    //Adopt the Best Fit One
    testClass<int,char> obj1;
    testClass<int*,int*> obj2;
    testClass<const int*,int*> obj3;
}

