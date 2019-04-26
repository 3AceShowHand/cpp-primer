//
// Created by king on 2019/4/26.
//

#include <fstream>
#include <iostream>
#include "TextBlobQuery.hpp"
#include "BlobQueryResult.hpp"

using namespace std;

void runQueries(ifstream& infile) {
    TextBlobQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main() {
    ifstream infile("../data/letter.txt");
    runQueries(infile);

    return 0;
}