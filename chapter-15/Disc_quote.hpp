//
// Created by king on 2019/5/2.
//

#ifndef CPP_PRIMER_DISC_QUOTE_HPP
#define CPP_PRIMER_DISC_QUOTE_HPP

#include "Quote.hpp"

class Disc_quote : public Quote {

public:
    Disc_quote() {
        std::cout << "Disc_quote()" << std::endl;
    }

    Disc_quote(const std::string& bookNo, double price, std::size_t qty, double disc):
    Quote(bookNo, price), quantity(qty), discount(disc) {
        std::cout << "Disc_quote(const std::string& bookNo, double price, std::size_t qty, double disc)" << std::endl;
    }

    double net_price(std::size_t count) const override = 0;

    ~Disc_quote() {
        std::cout << "~Disc_quote()" << std::endl;
    }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};


#endif //CPP_PRIMER_DISC_QUOTE_HPP
