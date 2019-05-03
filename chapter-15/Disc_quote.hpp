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

    Disc_quote(const Disc_quote& other):
    Quote(other), quantity(other.quantity), discount(other.discount) {
        std::cout << "Disc_quote(const Disc_quote& other)" << std::endl;
    }

    Disc_quote& operator=(const Disc_quote& other) {
        if (this != &other) {
            Quote::operator=(other);
            quantity = other.quantity;
            discount = other.discount;
        }

        std::cout << "operator=(const Disc_quote& other)" << std::endl;

        return *this;
    }

    Disc_quote(Disc_quote&& other) noexcept :
    Quote(other), quantity(std::move(other.quantity)), discount(std::move(other.discount)) {
        std::cout << "Disc_quote(Disc_quote&& other)" << std::endl;
    }

    Disc_quote& operator=(Disc_quote&& other) noexcept {
        if (this != &other) {
            Quote::operator=(other);
            quantity = std::move(other.quantity);
            discount = std::move(other.discount);
        }
        std::cout <<"operator=(Disc_quote&& other)" << std::endl;

        return *this;
    }

    double net_price(std::size_t count) const override = 0;

    std::pair<size_t, double> discount_policy() const {
        return {quantity, discount};
    }

    ~Disc_quote() {
        std::cout << "~Disc_quote()" << std::endl;
    }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;

};

#endif //CPP_PRIMER_DISC_QUOTE_HPP
