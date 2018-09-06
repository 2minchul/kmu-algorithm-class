//
// Created by user on 18. 9. 7.
//

#include "develop.h"
#include <iostream>

void print_arr(int *arr, int i) {


    for (int _i = 0; _i < i; _i++) {
        std::cout << arr[_i] << ' ';
    }
    std::cout << std::endl;

}