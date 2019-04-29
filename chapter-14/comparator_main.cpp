//
// Created by king on 2019/4/29.
//


#include <iostream>
#include <functional>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10, 20);
    cout << sum << endl;

    sum = intNegate(intAdd(20, 30));
    cout << sum << endl;

    vector<int> vec{3, 4, 1, 5, 9, 2, 6, 7, 0, 11, -5, 3, 9};
    sort(vec.begin(), vec.end());
    for (const auto& item: vec) {
        cout << item << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end(), greater<int>());
    for (const auto& item: vec) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
