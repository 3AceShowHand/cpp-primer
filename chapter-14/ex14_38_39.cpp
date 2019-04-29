//
// Created by king on 2019/4/29.
//

#include <iostream>

using namespace std;

class StringEqualCompare {

public:
    StringEqualCompare(size_t i_) : i(i_) {

    }

    bool operator()(std::string& s) {
        return s.size() == i;
    }

private:
    size_t i;

};


int main() {

    string s{"hello"};

    StringEqualCompare compartor(5);

    cout << compartor(s) << endl;



    return 0;
}