
//
// Created by cheyulin on 8/27/16.
//
#include <boost/call_traits.hpp>
#include <cassert>

using namespace boost;

template<typename T>
class demo_class {
public:
    typedef typename call_traits<T>::value_type v_type;
    typedef typename call_traits<T>::param_type p_type;
    typedef typename call_traits<T>::reference r_type;
    typedef typename call_traits<T>::const_reference cr_type;

private:
    v_type v;
public:
    demo_class(p_type p) : v(p) {}

    v_type value() {
        return v;
    }

    r_type get() {
        return v;
    }
};

void test_demo_class() {
    int a[3] = {1, 2, 3};
    demo_class<int[3]> di(a);
    assert(di.value()[0] == 1);

    char c = 'A';
    demo_class<char &> dc(c);
    assert(dc.get() == c);
}

int main() {
    test_demo_class();
}