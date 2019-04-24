//
// Created by king on 2019/4/20.
//

#include <iostream>
#include <vector>


void printVector(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	if (begin != end) {
		std::cout << *begin << " ";
		printVector(begin + 1, end);
	}
}


int main() {
	std::vector<int> vec{1, 2, 3, 4, 5};
	printVector(vec.cbegin(), vec.cend());
	
	return 0;
}
