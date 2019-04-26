//
// Created by king on 2019/4/26.
//

#include <fstream>
#include <sstream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"

using namespace std;

TextQuery::TextQuery(ifstream &infile)
: lines(new vector<string>)
{
    string text;
    while (getline(infile, text)) {
        lines->push_back(text);
        int n = lines->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto& line_num = records[word];
            if (!line_num) {
                line_num.reset(new set<line_no>);
            }
            line_num->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = records.find(sought);
    if (loc == records.end()) {
        return QueryResult(sought, nodata, lines);
    }
    return QueryResult(sought, loc->second, lines);
}

