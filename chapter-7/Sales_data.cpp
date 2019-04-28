//
// Created by king on 2019/4/21.
//

#include "Sales_data.h"

Sales_data &Sales_data::combine(const Sales_data &rhs) {
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	
	return *this;
}

double Sales_data::avg_price() const {
	if (this->units_sold != 0) {
		return this->revenue / this->units_sold;
	}
	return 0;
}

//Sales_data add(const Sales_data & a, const Sales_data & b) {
//	Sales_data sum = a;
//	sum.combine(b);
//
//	return sum;
//}

//std::ostream &print(std::ostream & os, const Sales_data & data) {
//	os << data.isbn() << " " << data.units_sold
//		<< " " << data.revenue << " " << data.avg_price() << std::endl;
//	return os;
//}
//
//std::istream &read(std::istream & is, Sales_data & data) {
//	double price = 0;
//	is >> data.bookNo >> data.units_sold >> price;
//	data.revenue = data.units_sold * price;
//
//	return is;
//}

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
    this->bookNo = rhs.bookNo;
    this->units_sold = rhs.units_sold;
    this->revenue = rhs.revenue;

    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
       << " " << item.avg_price() << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }

    return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;

    return sum;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}
