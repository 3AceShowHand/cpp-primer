//
// Created by king on 2019/4/24.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream ifs(string("../data/letter.txt"));
    istream_iterator<string> in(ifs), eof;

    map<string, size_t> word_count;
    set<string> exclude = {"The, But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};

    while (in != eof) {
        if (exclude.find(*in) == exclude.end()) {
            word_count[*in] += 1;
        }
        ++in;
    }

    for (const auto& item: word_count) {
        cout << item.first << " occurs " << item.second
                << ((item.second > 1) ? " times ": " time") << endl;
    }

    return 0;
}