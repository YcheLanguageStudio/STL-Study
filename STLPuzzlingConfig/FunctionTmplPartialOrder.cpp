//
// Created by cheyulin on 7/12/16.
//

#include <iostream>


using namespace std;

class alloc {

};

//Function Partial Order
//Partial Specialization of Function templates


template<class T, class Alloc = alloc>
class vector {
public:
    void swap(vector<T, Alloc> &) {
        cout << "swap()" << endl;
    }
};

template <class T, class Alloc>
inline void swap(vector<T, Alloc>&x , vector<T, Alloc>&y){
    x.swap(y);
};

int main(){
    vector<int> x,y;
    swap(x,y);
}