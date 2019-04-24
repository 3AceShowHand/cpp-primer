//
// Created by king on 2019/4/20.
//

#include <vector>
#include <iostream>

int main() {
	std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		*it = *it * 2;
	}
	for (auto it = v1.cbegin(); it != v1.cend(); ++it) {
		std::cout << *it << " " ;
	}
	std::cout << std::endl;
	return 0;
}