//
// Created by king on 2019/4/20.
//

#include <string>
#include <iostream>

bool is_containCapital(const std::string& s) {
	for (auto it = s.cbegin(); it != s.cend(); ++it) {
		if (isupper(*it)) {
			return true;
		}
	}
	return false;
}

void str2letter(std::string& s) {
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (isalpha(*it)) {
			*it = tolower(*it);
		}
	}
}

int main() {
	std::string str1{"Halo scu"};
	std::cout << is_containCapital(str1) << std::endl;
	
	std::cout << "before convert " << str1 << std::endl;
	str2letter(str1);
	std::cout << "after convert " << str1 << std::endl;
	
	return 0;
}