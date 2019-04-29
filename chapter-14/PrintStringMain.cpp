//
// Created by king on 2019/4/29.
//

#include "PrintString.hpp"

using namespace std;

int main() {

    PrintString printer;

    string s = "hello";
    printer(s);

    PrintString errors(cerr, '\n');
    errors(s);

    return 0;
}