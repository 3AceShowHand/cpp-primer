//
// Created by king on 2019/5/1.
//

#ifndef CPP_PRIMER_QUOTE_HPP
#define CPP_PRIMER_QUOTE_HPP

#include <iostream>
#include <string>


class Quote {
public:

    Quote() {
        std::cout << "Quote()" << std::endl;
    }

    Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) {
        std::cout << "Quote(const std::string& book, double sale_price)" << std::endl;
    }

    std::string isbn() const {
        return bookNo;
    }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual void debug() const {
        std::cout << "bookNo = " << bookNo << std::endl;
        std::cout << "price = " << price << std::endl;
    }

    virtual ~Quote() {
        std::cout << "~Quote()" << std::endl;
    }

private:
    std::string bookNo;  // bookNo should only be accessed by isbn() in the base class.

protected:
    double price = 0.0;  // price can be accessed in other derived methods, should be protected.
};

#endif //CPP_PRIMER_QUOTE_HPP