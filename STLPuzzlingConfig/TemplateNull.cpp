//
// Created by cheyulin on 7/2/16.
//

#include <iostream>

using namespace std;

#define _STL_TEMPLATE_NULL template<>
//#define _STL_TEMPLATE_NULL Not Supported In GCC5.3 Perhaps
namespace yche {
    template<class Key>
    struct hash {
        void operator()() {
            cout << "hash<T>" << endl;
        }
    };

//explicit specialization
    _STL_TEMPLATE_NULL struct hash<char> {
        void operator()() {
            cout << "hash<char>" << endl;
        }
    };

    _STL_TEMPLATE_NULL struct hash<unsigned char> {
        void operator()() {
            cout << "hash<unsigned char>" << endl;
        }
    };
}

int main() {
    yche::hash<long> t1;
    yche::hash<char> t2;
    yche::hash<unsigned char> t3;
    t1();
    t2();
    t3();
}