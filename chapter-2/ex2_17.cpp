//
// Created by king on 2019/4/20.
//
#include <iostream>

int main() {
	int i, &ri = i;
	i = 5;
	ri = 10;
	std::cout << i << " " << ri << std::endl;
	
	return 0;
}
