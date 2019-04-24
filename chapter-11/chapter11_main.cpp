//
// Created by king on 2019/4/24.
//

#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;


int main() {

    vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    for (const auto& item: set2) {
        cout << item << " ";
    }
    cout << endl;

    set2.insert({1, 3, 5, 7, 9});
    for (const auto& item: set2) {
        cout << item << " ";
    }
    cout << endl;

    map<string, int> word_count;
    string word;

    ifstream ifs("../data/letter.txt");
    istream_iterator<string> in(ifs), eof;

    if (ifs) {
        while (in != eof) {
            auto ret = word_count.insert({*in++, 1});
            if (!ret.second) {
                ++ret.first->second;
            }
        }
    }
    for (const auto& item: word_count) {
        cout << item.first << " " << item.second << endl;
    }

    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});

    cout << "the size of authors: " << authors.size() << endl;
    for (const auto& item : authors) {
        cout << item.first << " " << item.second << endl;
    }
    auto cnt = authors.erase("Barth, John");
    cout << "delete " << cnt << (cnt > 1 ? " items ": " item ") << "from author multimap" << endl;
    cout << "the size of authors: " << authors.size() << endl;

    return 0;
}