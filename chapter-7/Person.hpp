//
// Created by king on 2019/4/21.
//

#ifndef CPP_PRIMER_PERSON_HPP
#define CPP_PRIMER_PERSON_HPP


#include <string>
#include <iostream>

class Person {
private:
	std::string name;
	std::string address;

public:
	
	Person(): name(""), address("") {
	
	}
	
	Person(const std::string& str1, const std::string& str2):
		name(str1), address(str2) {
		
	}
	
	explicit Person(const std::string& str1): name(str1) {
	
	}
	
	Person(std::istream& is) {
		std::cout << "please enter name: " << std::endl;
		is >> this->name;
		std::cout << "please enter address: " << std::endl;
		is >> this->address;
	}
	
	std::string getName() const { return name;}
	std::string getAddress() const { return address;}
	
	void setName(const std::string& name) {this->name = name;}
	void setAddress(const std::string& addr) {this->address = addr;}
};

std::istream& read(std::istream& is, Person& p);
std::ostream& print(std::ostream& os, const Person& p);

#endif //CPP_PRIMER_PERSON_HPP
