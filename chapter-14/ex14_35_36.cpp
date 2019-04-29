//
// Created by king on 2019/4/29.
//

#include <iostream>
#include <vector>

using namespace std;


class InputString {
public:
    InputString(std::istream& is= std::cin): is(is) {

    }

    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream& is;
};


int main() {
    InputString input;
    vector<string> vec;

    for (int i = 0; i < 5; ++i) {
        vec.push_back(input());
    }

    for (const auto& item: vec) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}