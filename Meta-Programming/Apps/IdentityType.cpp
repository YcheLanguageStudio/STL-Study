//
// Created by cheyulin on 7/15/16.
//

#include "../MetaFunctionTool.h"
#include <boost/type_traits.hpp>
#include <map>
#include <boost/foreach.hpp>
#include <boost/utility.hpp>
#include <iostream>

using namespace boost;

int main() {
    std::map<int, int> m;
    for (auto i = 0; i < 6; i++)
        m.insert(std::move(std::make_pair<int, int>(std::move(i), i + 1)));
    BOOST_FOREACH(BOOST_IDENTITY_TYPE((std::pair<int, int>))
                          x, m) { std::cout << x.first << ',' << x.second << '\n'; };

    //等价于
    BOOST_FOREACH(function_traits<void(std::pair<int, int>)>::arg1_type x, m) {
                    std::cout << x.first << ',' << x.second << '\n';
                };

}