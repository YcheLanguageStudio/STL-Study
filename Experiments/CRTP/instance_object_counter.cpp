//
// Created by cheyulin on 7/21/16.
//

#include "object_counter.h"

using namespace std;

class X : public counter<X> {
    // ...
};

class Y : public counter<Y> {
    // ...
};

void construct() {
    X x;
    cout << "X alive:" << X::objects_alive << endl;
    Y y;
    cout << "Y alive:" << Y::objects_alive << endl;

}

int main() {
    construct();
    construct();
    cout << "X alive:" << X::objects_alive << endl;
    cout << "X created:" << X::objects_created << endl;
    cout << "Y alive:" << Y::objects_alive << endl;
    cout << "Y created:" << Y::objects_created << endl;
}
