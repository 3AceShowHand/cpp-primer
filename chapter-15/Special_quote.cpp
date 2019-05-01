//
// Created by king on 2019/5/1.
//

#include "Special_quote.hpp"

double Special_quote::net_price(std::size_t n) const {
    if (n <= threshold) {
        return n * (1 - discount) * price;
    } else {
        std::size_t remained = n - threshold;
        return remained * price + threshold * (1 - discount) * price;
    }
}
