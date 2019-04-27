//
// Created by king on 2019/4/27.
//

#include "Folder.hpp"
#include "Message.hpp"

using namespace std;

int main() {

    Message m1("This is a message");
    Message m2("This is also a message");
    Message m3;
    m3 = m1;

    return 0;
}