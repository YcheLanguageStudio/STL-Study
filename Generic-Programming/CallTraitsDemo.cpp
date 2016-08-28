
//
// Created by cheyulin on 8/27/16.
//
#include <boost/call_traits.hpp>
#include <cassert>
#include <string>

using namespace boost;
using namespace std;

call_traits<string>::value_type scat(call_traits<string>::param_type s1, call_traits<string>::param_type s2) {
    assert(std::is_reference<call_traits<string>::param_type>::value);
    assert((std::is_same<call_traits<string>::param_type, const string &>::value));
    return s1 + s2;
}

void demo_function() {
    scat("1", "2");
}

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
    demo_function();
    test_demo_class();
}