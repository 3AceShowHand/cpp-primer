//
// Created by king on 2019/4/20.
//

#include <iostream>

int ex6_21(int a, const int* b) {
	if (a > *b) return a;
	return *b;
}

void swap_pointer(int* &a, int* &b) {
	std::cout << "before swap pointer a is " << a << " b is " << b << std::endl;
	int * t = a;
	a = b;
	b = t;
	std::cout << "after swap pointer a is " << a << " b is " << b << std::endl;
}

void print(const int* beg, const int* end) {
	while (beg != end) {
		std::cout << *beg++ << std::endl;
	}
}

void print(const int ia[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << ia[i] << std::endl;
	}
}

void print(const int ia[10]) {
	for (size_t i = 0; i != 10; ++i) {
		std::cout << ia[i] << std::endl;
	}
}

int main() {
	int a = 5, b = 10;
	std::cout << ex6_21(a, &b) << std::endl;
	
	auto pa = &a;
	auto pb = &b;
	swap_pointer(pa, pb);
	
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(arr);
	
	// this will excceed the boundary of the array, dangerous!
	int arr2[5] = {0, 2, 4, 6, 8};
	print(arr2);
	return 0;
}
