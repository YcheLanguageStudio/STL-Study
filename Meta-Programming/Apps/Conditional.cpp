//
// Created by cheyulin on 7/15/16.
//

#include "../MetaFunctionTool.h"
#include <boost/type_traits.hpp>

using namespace boost;

//MetaFunction, 使用了元函数转发
mp_arglist<mp_arg T>
mp_function demo_func : conditional<
        is_pointer<T>::value, typename add_const<typename remove_pointer<T>::type>::type,
        typename add_pointer<typename add_const<T>::type>::type> {
};

//另一种方式
mp_arglist<mp_arg T>
mp_function demo_func2 :
        mpl::eval_if<
                is_pointer<T>,
                add_const<typename remove_pointer<T>::type>,
                add_pointer<typename add_const<T>::type>
        > {
};

int main() {
    assert((boost::is_same<mp_exec(demo_func<int>), const int *>::value));
    assert((boost::is_same<mp_exec(demo_func<int *>), const int>::value));

    assert((boost::is_same<mp_exec(demo_func2<int>), const int *>::value));
    assert((boost::is_same<mp_exec(demo_func2<int *>), const int>::value));
}