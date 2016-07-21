//
// Created by cheyulin on 7/21/16.
//
#include "base.h"

using namespace yche;
using namespace std;
namespace yche {
    class MyClass : public MyTemplate<MyClass> {
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
    my_class.method();
}