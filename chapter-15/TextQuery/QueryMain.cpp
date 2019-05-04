//
// Created by king on 2019/5/3.
//


#include <fstream>
#include <iostream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"


void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter word to look for, or 'q' to exit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main() {
    std::string filename("../data/query_text.txt");
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return -1;
    }
    runQueries(in);
    return 0;
}