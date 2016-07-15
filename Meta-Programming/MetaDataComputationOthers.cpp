//
// Created by cheyulin on 7/14/16.
//

#include "boost/type_traits.hpp"
#include "MetaFunctionTool.h"

using namespace boost;

int main() {
    mp_data common_type<int, char>::type metadata1;
    assert((is_same<metadata1, int>::value));

    mp_data common_type<int, double>::type metadata2;
    assert((is_same<metadata2, double>::value));

    //Int 和String  没有共同类型

    char msg[] = "abcd";
    mp_data mp_exec(decay<decltype(msg)>) metadata3;
    assert((is_same<metadata3, char *>::value));
}