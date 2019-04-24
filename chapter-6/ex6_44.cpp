//
// Created by king on 2019/4/21.
//

#include <iostream>
#include <string>

inline bool isShorter(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

 // this function cannot be called.
constexpr bool isShorter2(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

int main() {
	std::string s1{"halo"};
	std::string s2{"fever"};
	
	std::cout << isShorter(s1, s2) << std::endl;
	
	// std::cout << isShorter2(s1, s2) << std::endl;
	
	
	return 0;
}