//
// Created by cheyulin on 12/17/16.
//

#include <cassert>

#include <boost/type_traits.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/if.hpp>

using namespace boost;
using namespace boost::mpl;

void DemoIntegerUsage() {
    using i2=int_<2>;
    using s2=integral_c<short, 2>;

    assert(i2::value == 2);
    assert(i2::value == s2::value);

    assert((is_same<i2::type, i2>::value));
    assert((is_same<s2::value_type, short>::value));

    assert(i2::next::value == 3);
    assert(prior<s2>::type::value == 1);

    i2 two1;
    s2 two2;
    int i = two1 + two2;
    assert(i == int_<4>());
}

void DemoBoolUsage() {
    assert(true_::value == true);
    assert(false_::value == false);

    assert((is_same<true_::type, bool_<true>>::value));
    assert((is_same<false_::value_type, bool>::value));
}

void DemoCalculation() {
    using i2= int_<2>;
    using i5= int_<5>;
    using i7= int_<7>;

    assert((plus<i2, i5, i7>::type::value == 14));
    assert((equal_to<minus<i7, i5>::type, i2>::type::value));

    assert((less<i2, i7>::type::value));
    assert((is_same<greater<i5, i2>::type, true_>::value));

    assert((not_<and_<true_, false_>::type>::type::value));
    assert((or_<true_, false_>::type()));
}

void DemoBranching() {
    using mdata1= if_c<true, int, long>::type;
    assert((is_same<mdata1, int>::value));

    using mdata2= if_<false_, float, double>::type;
    assert((is_same<mdata2, double>::value));

    using mdata3 = if_<is_integral<mdata2>, integral_promotion<mdata2>::type, floating_point_promotion<mdata2>::type>::type;
    assert((is_same<mdata3, double>::value));
}

int main() {
    DemoIntegerUsage();
    DemoBoolUsage();
    DemoCalculation();
    DemoBranching();
}