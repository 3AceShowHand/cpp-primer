//
// Created by king on 2019/5/1.
//

#include "Special_quote.hpp"

double Special_quote::net_price(std::size_t n) const {
    if (n <= quantity) {
        return n * (1 - discount) * price;
    } else {
        std::size_t remained = n - quantity;
        return remained * price + quantity * (1 - discount) * price;
    }
}
