//
// Created by king on 2019/5/3.
//

#include <algorithm>
#include "AndQuery.hpp"

QueryResult AndQuery::eval(const TextQuery &tq) const {
    std::cout << "AndQuery::eval(const TextQuery& tq) const" << std::endl;

    auto left = lhs.eval(tq);
    auto right = rhs.eval(tq);

    auto ret_lines = std::make_shared<std::set<line_no_t>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
            inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}