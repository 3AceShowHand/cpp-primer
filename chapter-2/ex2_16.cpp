//
// Created by king on 2019/4/20.
//
#include <iostream>

int main() {
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	r2 = 3.14159;    // d = 3.1415926
	r2 = r1;          // 0
	i = r2;           // 3
	r1 = d;           // 3
	
	std::cout << "i :" << i << std::endl;
	std::cout << "r1:" << r1 <<std::endl;
	std::cout << "d :" << d << std::endl;
	std::cout << "r2:" << r2 << std::endl;
	
	return 0;
}
