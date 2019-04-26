//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_TEXTQUERY_HPP
#define CPP_PRIMER_TEXTQUERY_HPP

#include <vector>
#include <map>
#include <string>
#include <set>
#include <memory>

class QueryResult;
class TextQuery {
    using line_no = std::vector<std::string>::size_type ;
public:
    // TextQuery() ;
    explicit TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& sought) const;

private:
    std::shared_ptr<std::vector<std::string>> lines;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> records;
};

#endif //CPP_PRIMER_TEXTQUERY_HPP
