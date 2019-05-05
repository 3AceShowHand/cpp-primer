//
// Created by king on 2019/5/5.
//

//void print(int (&arr)[10]) {
//    for (auto elem: arr) {
//        cout << elem << endl;
//    }
//}

#include <iostream>

template <class T_Val, unsigned N>
void print(const T_Val(&arr)[N]) {
    for (const auto& item: arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    print(arr);

    double arr2[] = {3.14, 1.72, 1.41, 2.72};
    print(arr2);

    return 0;
}