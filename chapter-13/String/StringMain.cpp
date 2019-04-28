//
// Created by king on 2019/4/28.
//

#include <vector>
#include "String.hpp"

using namespace std;

int main() {
    String s1("hello");
    String s2("world");
    String s3("fuck");
    // String s4("c++");

    vector<String> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    // v.push_back(s4);

    return 0;
}