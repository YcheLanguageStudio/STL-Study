//
// Created by cheyulin on 7/3/16.
//

#include "YcheAllocator.h"

#include <vector>
#include <iostream>

int main() {
    int ia[5] = {0, 1, 2, 3, 4};
    unsigned int i;
    vector<int, yche::allocator<int>> iv(ia, ia + 5);
    for (i = 0; i < iv.size(); i++) {
        cout <<iv[i]<<' ';
    }
    cout << endl;
}