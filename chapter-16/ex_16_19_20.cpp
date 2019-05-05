//
// Created by king on 2019/5/5.
//

#include <vector>
#include <iostream>

template <class T_Container>
void print(const T_Container& c) {
    for (typename T_Container::size_type i = 0; i != c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

template <class T_Container>
void iter_print(const T_Container& c) {
    for (auto iter = c.cbegin(); iter != c.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec1{1, 2, 3, 4, 5};
    print(vec1);

    iter_print(vec1);

    return 0;
}