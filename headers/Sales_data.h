//
// Created by king on 2019/4/20.
//

#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data;

std::ostream& operator<<(std::ostream& os, const Sales_data& item);
std::istream& operator>>(std::istream& is, Sales_data& item);

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
bool operator==(const Sales_data& lhs, const Sales_data& rhs);
bool operator!=(const Sales_data& lhs, const Sales_data& rhs);

class Sales_data {

    friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);
    friend std::istream& operator>>(std::istream& is, Sales_data& item);

    friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

    friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);

public:
	
	Sales_data(): Sales_data("", 0, 0) {
		std::cout << "Sales_data()" << std::endl;
	}

	Sales_data(const Sales_data& s):Sales_data(s.bookNo, s.units_sold, s.revenue) {
	    std::cout << "Sales_data(const Sales_data& s)" << std::endl;
	}

	explicit Sales_data(const std::string& s): Sales_data(s, 0, 0) {
		std::cout << "explicit Sales_data(const std::string& s)" << std::endl;
	}

	Sales_data(const std::string& s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p * n) {
		std::cout << "Sales_data(const std::string& s, unsigned n, double p)" << std::endl;
	}
	
	explicit Sales_data(std::istream& is): Sales_data() {
		std::cout << "explicit Sales_data(std::istream& is)" << std::endl;
//		read(is, *this);
        is >> *this;
	}

	explicit operator std::string() const {
	    return this->bookNo;
	}

    explicit operator double() const {
        return revenue;
	}

	Sales_data& operator=(const Sales_data& rhs);
	
	std::string isbn() const {
		return bookNo;
	}
	
	Sales_data& combine(const Sales_data&);

    Sales_data& operator+=(const Sales_data& rhs);
	
	double avg_price() const;

private:
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};

inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn().size() < rhs.isbn().size();
}

#endif //CPP_PRIMER_SALES_DATA_H
