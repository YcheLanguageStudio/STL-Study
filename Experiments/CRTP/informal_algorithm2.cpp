//
// Created by cheyulin on 7/21/16.
//
#include "informal_base2.h"
using namespace yche;
using namespace std;
namespace yche {
    class MyClass{
    public:
        void print1() {
            cout << "member print1" << endl;
        }

        void print2() {
            cout << "member print2" << endl;
        }
    };
}

int main() {
    MyClass my_class;
    MyTemplate<MyClass> my_template(&my_class);
    my_template.method();
}