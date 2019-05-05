//
// Created by king on 2019/5/5.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T_Iter, typename T_Val>
T_Iter find(T_Iter first, T_Iter last, const T_Val& v) {
    while (first != last) {
        if (*first == v) {
            return first;
        }
        ++first;
    }
    return last;
}

int main() {
    std::vector<int> vec1{1, 3, 5, 2, 4, 6};

    std::cout << *(find(vec1.cbegin(), vec1.cend(), 5)) << std::endl;
    std::cout << *(find(vec1.cbegin(), vec1.cend(), 0)) << std::endl;
    std::cout << *(find(vec1.cbegin(), vec1.cend(), 1)) << std::endl;
    std::cout << *(find(vec1.cbegin(), vec1.cend(), 6)) << std::endl;

    return 0;
}