//
// Created by king on 2019/4/29.
//


#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int add(int a, int b) {
    return a + b;
}

auto mod = [] (int a, int b) {
    return a % b;
};

struct divide {
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};


int main() {
    map<string, function<int (int, int)>> binops;

    binops.insert({"+", add});
    binops.insert({"-", std::minus<int>()});
    binops.insert({"/", divide()});
    binops.insert({"*", [](int i, int j) {return i + j;}});
    binops.insert({"%", mod});

    return 0;
}
