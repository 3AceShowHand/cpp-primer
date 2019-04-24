//
// Created by king on 2019/4/20.
//
#include <iostream>

int product(int a, int b) {
	return a * b;
}


int main() {
	int a, b;
	std::cout << "please enter two int value a and b" << std::endl;
	std::cin >> a >> b;
	int result = product(a, b);
	std::cout << result << std::endl;
	
	return 0;
}
