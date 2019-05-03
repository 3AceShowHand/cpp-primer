//
// Created by king on 2019/5/4.
//

#ifndef CPP_PRIMER_TEXTQUERY_HPP
#define CPP_PRIMER_TEXTQUERY_HPP


#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    using line_no_t = std::vector<std::string>::size_type ;

    explicit TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& sought) const;

private:
    std::shared_ptr<std::vector<std::string>> lines;
    std::map<std::string, std::shared_ptr<std::set<line_no_t>>> records;

};


#endif //CPP_PRIMER_TEXTQUERY_HPP
