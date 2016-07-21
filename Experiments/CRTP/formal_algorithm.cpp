//
// Created by cheyulin on 7/21/16.
//
#include "formal_base.h"

using namespace yche;
using namespace std;

namespace yche {
    struct Derived : public Base<Derived> {
        void implementation();

        static void static_sub_func();
    };

    void Derived::implementation() {
        cout << "Impl of Interface" << endl;
    }
}

int main(){
    Derived derived;
    derived.template_method();
}