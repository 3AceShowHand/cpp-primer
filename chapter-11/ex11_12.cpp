//
// Created by king on 2019/4/24.
//

#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;


int main() {
    ifstream int_reader("../data/ints.txt");
    ifstream str_reader("../data/words.txt");

    istream_iterator<int> int_iter(int_reader), int_eof;
    istream_iterator<string> str_iter(str_reader), str_eof;

    vector<pair<string, int>> ret;

    while (int_iter != int_eof && str_iter != str_eof) {
        ret.push_back(make_pair(*str_iter++, *int_iter++));
    }

    while (int_iter != int_eof) {
        ret.push_back(make_pair("", *int_iter++));
    }

    while (str_iter != str_eof) {
        ret.push_back(make_pair(*str_iter++, 0));
    }

    for (const auto& item: ret) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}