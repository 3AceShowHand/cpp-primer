//
// Created by king on 2019/5/1.
//

#include "Bulk_quote.hpp"

double Bulk_quote::net_price(std::size_t n) const {
    if (n > quantity) {
        return n * (1 - discount) * price;
    }
    return n * price;
}
