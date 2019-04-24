//
// Created by king on 2019/4/20.
//
#include <vector>
#include <iostream>


template <class T>
void printVector(const std::vector<T>& v) {
	for (auto it = v.cbegin(); it <v.cend() ; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::vector<int> v1;
	int value;
	while (std::cin >> value) {
		v1.push_back(value);
		printVector(v1);
	}
	
	return 0;
}
