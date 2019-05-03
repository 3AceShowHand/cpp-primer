//
// Created by king on 2019/5/4.
//

#ifndef CPP_PRIMER_QUERYRESULT_HPP
#define CPP_PRIMER_QUERYRESULT_HPP

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <set>

class QueryResult {
    using line_no_t = std::vector<std::string>::size_type ;
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:

    QueryResult(std::string s, std::shared_ptr<std::set<line_no_t>> p,
                std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {
    }

    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }

    std::set<line_no_t>::iterator begin() {
        return lines->begin();
    }

    std::set<line_no_t>::iterator end() {
        return lines->end();
    }

    const std::set<line_no_t>::const_iterator cbegin() const {
        return lines->cbegin();
    }

    const std::set<line_no_t>::const_iterator cend() const {
        return lines->cend();
    }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no_t>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif //CPP_PRIMER_QUERYRESULT_HPP
