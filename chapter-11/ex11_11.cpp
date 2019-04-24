//
// Created by king on 2019/4/24.
//

#include <set>
#include "Sales_data.h"

auto less(const Sales_data& lhr, const Sales_data& rhs) {
    return lhr.isbn() < rhs.isbn();
}

int main() {
    using Less = bool(*)(const Sales_data& lhs, const Sales_data& rhs);
    std::multiset<Sales_data, Less> bookstore(less);

    return 0;
}