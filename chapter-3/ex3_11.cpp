//
// Created by king on 2019/4/20.
//

#include <iostream>
#include <string>

int main() {
	const std::string s = "Keep out!";
	
	for (auto &c: s) {
		std::cout << c << " ";
	}
	
	return 0;
	
}