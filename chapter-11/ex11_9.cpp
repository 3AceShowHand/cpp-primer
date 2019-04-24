//
// Created by king on 2019/4/24.
//

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;


int main() {
    ifstream ifs("../data/letter.txt");

    string buf;
    map<string, list<int>> ret;

    int line = 0;
    if (ifs) {
        while (getline(ifs, buf)) {
            stringstream ss(buf);
            string word;
            while (ss >> word) {
                ret[word].push_back(line);
            }
            line += 1;
        }
    }

    for (const auto& item: ret) {
        cout << item.first << " : ";
        for (const auto& x: item.second) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}