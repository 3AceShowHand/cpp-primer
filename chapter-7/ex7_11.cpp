//
// Created by king on 2019/4/21.
//

#include "Sales_data.h"

int main() {
	
	Sales_data x0;
	
	Sales_data x1{"bookNo-1", 2, 50};
	Sales_data x2{"bookNo-2"};
	
	// Sales_data x3(std::cin);

	std::cout << x0;
	std::cout << x1;
	std::cout << x2;
//	print(std::cout, x0);
//	print(std::cout, x1);
//	print(std::cout, x2);
//
//	print(std::cout, x3);
//
	return 0;
}
