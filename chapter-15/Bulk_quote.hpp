//
// Created by king on 2019/5/1.
//

#ifndef CPP_PRIMER_BULK_QUOTE_HPP
#define CPP_PRIMER_BULK_QUOTE_HPP

#include "Quote.hpp"

class Bulk_quote: public Quote {

public:
    Bulk_quote() {
        std::cout << "Bulk_quote()" << std::endl;
    }

    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
    Quote(book, p), min_qty(qty), discount(disc) {
        std::cout << "Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)" << std::endl;
    }

    double net_price(std::size_t n) const override ;

    ~Bulk_quote() {
        std::cout << "~Bulk_quote()" << std::endl;
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;

};


#endif //CPP_PRIMER_BULK_QUOTE_HPP
