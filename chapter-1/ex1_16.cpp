//
// Created by king on 2019/4/20.
//

#include <iostream>

int main() {
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is :" << sum << std::endl;
	return 0;
}