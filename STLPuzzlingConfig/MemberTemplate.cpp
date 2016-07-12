//
// Created by cheyulin on 7/12/16.
//

#include <iostream>

using namespace std;

class alloc {

};

template<class T, class Alloc=alloc>
class vector {
public:
    typedef T value_type;
    typedef value_type *iterator;

    template<class I>
    void insert(iterator position, I first, I last) {
        cout << "insert" << endl;
    }
};

int main() {
    int ia[5] = {0, 1, 2, 3, 4};

    vector<int> x;
    vector<int>::iterator iter;
    x.insert(iter, ia, ia + 5);//Interesting Deduce the Type of I
}