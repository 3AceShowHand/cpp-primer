//
// Created by king on 2019/4/26.
//

#include <iostream>
#include <string>
#include <memory>

int main() {

    int n = 3;

    std::allocator<std::string> alloc;
    auto p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while (q != p + n && std::cin >> s) {
        alloc.construct(q++, s);
    }
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);

    return 0;
}