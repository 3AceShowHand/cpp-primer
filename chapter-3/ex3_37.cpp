//
// Created by king on 2019/4/20.
//

#include <iostream>

int main() {
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char * op = ca;
	while (*op) {
		std::cout << *op << std::endl;
		++op;
	}
	
	return 0;
}