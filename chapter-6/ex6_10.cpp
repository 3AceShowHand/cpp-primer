//
// Created by king on 2019/4/20.
//

#include <iostream>

void mySwap(int* a, int* b) {
	std::cout << "before swap a is " << *a << " b is " << *b << std::endl;
	int t = *a;
	*a = *b;
	*b = t;
	std::cout << "after swap a is " << *a << " b is" << *b << std::endl;
}

int main() {
	int a = 3;
	int b = 5;
	mySwap(&a, &b);
	
	return 0;
}