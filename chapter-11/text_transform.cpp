//
// Created by king on 2019/4/24.
//
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, string> buildMap(ifstream& map_file) {
    map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            // if a key happen multiple times, the last one will be stored.
            // trans_map[key] = value.substr(1);
            // if a key happend multiple times, the first one will be stored, others will be ignored,
            // since the key already in the map.
            trans_map.insert({key, value.substr(1)});
        } else {
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string& transform(const string& s, const map<string, string> rules) {
    auto map_it = rules.find(s);
    if (map_it != rules.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}

void word_transform(ifstream& map_file, ifstream& input) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        string s;
        while (stream >> word) {
            word = transform(word, trans_map);
            if (firstword) {
                s = word;
                firstword = false;
            } else {
                s.append(" ");
                s.append(word);
            }
        }
        s.erase(remove(s.begin(), s.end(), '\r'), s.end());
        cout << s << endl;
    }
}


int main() {
    ifstream map_file("../data/transform_rules.txt");
    ifstream input("../data/transform_text.txt");

    word_transform(map_file, input);

    return 0;
}
