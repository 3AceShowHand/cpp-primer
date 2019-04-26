//
// Created by king on 2019/4/26.
//

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "TextBlobQuery.hpp"
#include "BlobQueryResult.hpp"

using namespace std;

TextBlobQuery::TextBlobQuery(std::istream &infile) {
    string line;
    while (getline(infile, line)) {
        file.push_back(line);
        int n = file.size() - 1;
        istringstream spliter(line);
        string word;
        while (spliter >> word) {
            auto& line_num = records[word];
            if (!line_num) {
                line_num.reset(new set<line_no_t>);
            }
            line_num->insert(n);
        }
    }
}

BlobQueryResult TextBlobQuery::query(const std::string &sought) const {
    static shared_ptr<set<line_no_t>> nodata(new set<line_no_t>);
    auto loc = records.find(sought);
    if (loc == records.end()) {
        return BlobQueryResult(sought, nodata, file);
    }
    return BlobQueryResult(sought, loc->second, file);

}