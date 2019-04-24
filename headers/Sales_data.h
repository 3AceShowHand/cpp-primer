//
// Created by king on 2019/4/20.
//

#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data;

Sales_data add(const Sales_data&, const Sales_data&);

std::ostream& print(std::ostream&, const Sales_data&);

std::istream& read(std::istream&, Sales_data&);

class Sales_data {
	
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);

public:
	
	Sales_data(): Sales_data("", 0, 0) {
		std::cout << "Sales_data()" << std::endl;
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
		read(is, *this);
	}
	
	std::string isbn() const {
		return bookNo;
	}
	
	Sales_data& combine(const Sales_data&);
	
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
