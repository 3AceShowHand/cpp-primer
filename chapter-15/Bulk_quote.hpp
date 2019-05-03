//
// Created by king on 2019/5/1.
//

#ifndef CPP_PRIMER_BULK_QUOTE_HPP
#define CPP_PRIMER_BULK_QUOTE_HPP


#include "Disc_quote.hpp"

class Bulk_quote: public Disc_quote {

public:
    Bulk_quote() {
        std::cout << "Bulk_quote()" << std::endl;
    }

    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
    Disc_quote(book, p, qty, disc) {
        std::cout << "Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)" << std::endl;
    }

    Bulk_quote(const Bulk_quote& other):
    Disc_quote(other) {
        std::cout << "Bulk_quote(const Bulk_quote& other)" << std::endl;
    }

    Bulk_quote& operator=(const Bulk_quote& other) {
        if (this != &other) {
            Disc_quote::operator=(other);
            std::cout << "operator=(const Bulk_quote& other)" << std::endl;
        }
        return *this;
    }

    Bulk_quote(Bulk_quote&& other) noexcept :
    Disc_quote(other) {
        std::cout <<"Bulk_quote(Bulk_quote&& other)" << std::endl;
    }

    Bulk_quote& operator=(Bulk_quote&& other) noexcept {
        if (this != &other) {
            Disc_quote::operator=(other);
        }
        std::cout << "operator=(Bulk_quote&& other)" << std::endl;

        return *this;
    }

    double net_price(std::size_t n) const override ;

    ~Bulk_quote() {
        std::cout << "~Bulk_quote()" << std::endl;
    }

    Bulk_quote* clone() const & {
        return new Bulk_quote(*this);
    }

    Bulk_quote* clone() && {
        return new Bulk_quote(std::move(*this));
    }

    virtual void debug() const override {
        Quote::debug();
        std::cout << "min_qty = " << quantity << std::endl;
        std::cout << "discount = " << discount << std::endl;
    }
};

#endif //CPP_PRIMER_BULK_QUOTE_HPP
