//
// Created by king on 2019/4/26.
//

#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    int n = 10;
    string* const p = new string[n];
    string s;
    string* q = p;
    while (cin >> s && q != p + n) {
        *q++ = s;
    }
    const size_t size = q - p;
    delete[] p;

    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    allocator<int> alloc;
    auto a = alloc.allocate(vec.size() * 2);
    auto b = uninitialized_copy(vec.begin(), vec.end(), a);
    uninitialized_fill_n(b, vec.size(), 42);


    return 0;
}