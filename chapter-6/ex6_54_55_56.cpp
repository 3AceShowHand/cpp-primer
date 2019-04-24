//
// Created by king on 2019/4/21.
//

#include <iostream>
#include <vector>


// both fine
int func(int a, int b);

int func(const int a, const int b);


typedef decltype(func) fp;

int add(const int a, const int b) {
	return a + b;
}

int sub(const int a, const int b) {
	return a - b;
}

int mul(const int a, const int b) {
	return a * b;
}

int divide(const int a, const int b) {
	return a / b;
}


std::vector<fp*> v{add, sub, mul, divide};

int main() {
	
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		std::cout << (*it)(2, 2) << std::endl;
	}
	
	return 0;
}