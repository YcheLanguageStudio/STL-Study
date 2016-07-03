//
// Created by cheyulin on 7/3/16.
//
#include <iostream>

using namespace std;
namespace  yche{
    template<class T>
    struct plus {
        T operator()(const T &x, const T &y) {
            return x + y;
        }
    };

    template <class T>
    struct minus{
        T operator()(const T &x, const T &y) {
            return x - y;
        }
    };

}

int main(){
    yche::plus<int> plusobj;
    yche::minus<int> minusobj;

    cout << plusobj(3,5)<<endl;
    cout << minusobj(3,5)<<endl;

    //Temp Object
    cout << yche::plus<int>()(3,5)<<endl;
    cout << yche::minus<int>()(3,5)<<endl;
}
