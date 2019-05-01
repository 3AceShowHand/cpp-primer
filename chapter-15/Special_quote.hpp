//
// Created by king on 2019/5/1.
//

#ifndef CPP_PRIMER_SPECIAL_QUOTE_HPP
#define CPP_PRIMER_SPECIAL_QUOTE_HPP


#include "Disc_quote.hpp"

class Special_quote: public Disc_quote{

public:
    Special_quote() {
        std::cout << "Special_quote()" << std::endl;
    }

    Special_quote(const std::string& book, double sales_price, std::size_t thresh, double disc):
    Disc_quote(book, sales_price, thresh, disc) {
        std::cout << "Special_quote(const std::string& book, double sales_price, "
                     "std::size_t thresh, double disc" << std::endl;
    }

    double net_price(std::size_t n) const override ;

    virtual void debug() const override {
        std::cout << "threshold = " << quantity << std::endl;
        std::cout << "discount = " << discount << std::endl;
    }
};


#endif //CPP_PRIMER_SPECIAL_QUOTE_HPP
