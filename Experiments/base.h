#include <iostream>

namespace yche {
    template<typename T>
    class MyTemplate {
        T *member;

    public:
        T *method() {
            member->print1();
            member->print2();
        }
        // ...
    };
}