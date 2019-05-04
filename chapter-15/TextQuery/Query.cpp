//
// Created by king on 2019/5/3.
//

#include "Query.hpp"

std::ostream &operator<<(std::ostream &os, const Query &query) {
    std::cout << "std::ostream& operator<<(std::ostream& os, const Query& query)" << std::endl;
    return os << query.rep();
}
