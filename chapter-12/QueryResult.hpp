//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_QUERYRESULT_HPP
#define CPP_PRIMER_QUERYRESULT_HPP

#include <set>
#include <memory>
#include <iostream>
#include <vector>

class QueryResult {
    using line_no = std::vector<std::string>::size_type ;
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
            std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {
    }

    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }

    std::set<line_no>::iterator begin() {
        return lines->begin();
    }

    std::set<line_no>::iterator end() {
        return lines->end();
    }

    const std::set<line_no>::const_iterator cbegin() const {
        return lines->cbegin();
    }

    const std::set<line_no>::const_iterator cend() const {
        return lines->cend();
    }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif //CPP_PRIMER_QUERYRESULT_HPP
