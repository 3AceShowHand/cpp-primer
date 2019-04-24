//
// Created by king on 2019/4/21.
//

#include "Person.hpp"
#include <iostream>

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

int main() {
	Person a;
	Person b(std::cin);
	
	print(std::cout, a);
	print(std::cout, b);
	
	return 0;
}

std::istream &read(std::istream &is, Person &p) {
	std::string str1, str2;
	is >> str1 >> str2;
	p.setName(str1);
	p.setAddress(str2);
	
	return is;
}

std::ostream &print(std::ostream &os, const Person &p) {
	os << p.getName() << " " << p.getAddress() << std::endl;
	return os;
}
