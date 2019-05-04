//
// Created by king on 2019/5/3.
//

#include "NotQuery.hpp"

QueryResult NotQuery::eval(const TextQuery &tq) const {
    std::cout << "NotQuery::eval(const TextQuery &tq) const" << std::endl;

    auto ret_lines = std::make_shared<std::set<line_no_t>>();
    auto result = query.eval(tq);
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n) {
            ret_lines->insert(n);
        } else if (beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}