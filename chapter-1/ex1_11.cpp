//
// Created by king on 2019/4/20.
//

#include <iostream>

int main() {
	std::cout << "please enter two number :" << std::endl;
	int a, b;
	std::cin >> a >> b;
	for (int i = a; i < b; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	return 0;
}