//
// Created by king on 2019/4/25.
//

#include <memory>
#include <cstring>
#include <iostream>

using namespace std;

void strcat(const char* str1, const char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int total = length1 + length2 + 1;

    unique_ptr<char[]> ret(new char[total]);
    int i = 0;
    for (int j = 0; j < length1; j++) {
        ret[i++] = str1[j];
    }
    for (int j = 0; j < length2; j++) {
        ret[i++] = str2[j];
    }
    ret[i] = '\0';

    for(int i = 0; ret[i] != '\0'; ++i) {
        cout << ret[i];
    }
    ret.release();
}

int main() {

    strcat("hello", "world");

    return 0;
}