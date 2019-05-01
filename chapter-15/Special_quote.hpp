//
// Created by king on 2019/5/1.
//

#ifndef CPP_PRIMER_SPECIAL_QUOTE_HPP
#define CPP_PRIMER_SPECIAL_QUOTE_HPP

#include "Quote.hpp"

class Special_quote: public Quote {

public:
    Special_quote() {
        std::cout << "Special_quote()" << std::endl;
    }

    Special_quote(const std::string& book, double sales_price, std::size_t thresh, double disc):
    Quote(book, sales_price), threshold(thresh), discount(disc) {
        std::cout << "Special_quote(const std::string& book, double sales_price, "
                     "std::size_t thresh, double disc" << std::endl;
    }

    double net_price(std::size_t n) const override ;

private:
    std::size_t threshold;
    double discount;
};


#endif //CPP_PRIMER_SPECIAL_QUOTE_HPP
