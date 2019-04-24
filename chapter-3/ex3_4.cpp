//
// Created by king on 2019/4/20.
//

#include <string>
#include <iostream>

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	
	if (s1 < s2) {
		std::cout << s2 << std::endl;
	} else {
		std::cout << s1 << std::endl;
	}
	
	return 0;
}
