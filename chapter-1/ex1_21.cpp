//
// Created by king on 2019/4/20.
//

#include <iostream>
#include "Sales_item.h"


int main() {
	Sales_item book1, book2;
	std::cin >> book1;
	std::cin >> book2;
	
	if (book1.isbn() != book2.isbn()) {
		std::cout << "book1 and book2 have different isbn, not the same book!" << std::endl;
		return -1;
	} else {
		std::cout << "The sum of book1 and book2 is :" << book1 + book2 << std::endl;
	}
	return 0;
}