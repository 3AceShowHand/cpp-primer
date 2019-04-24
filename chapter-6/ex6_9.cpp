//
// Created by king on 2019/4/20.
//

#include <iostream>
#include "chapter6.hpp"

int fact(int n) {
	if (n == 1) return n;
	return n * fact(n - 1);
}

int interactive_act() {
	std::cout << "please enter a int :" << std::endl;
	int n;
	std::cin >> n;
	int res = fact(n);
	std::cout << "The factorial of " << n << " is " << res << std::endl;
	
	return 0;
}

std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs) {
	auto ret = s.size();     // set as the last position + 1
	occurs = 0;
	for (decltype(s.size())i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			if (ret == s.size()) {
				ret = i;
			}
			++occurs;
		}
	}
	return ret;
}

bool is_sentence(const std::string &s) {
	decltype(s.size()) ctr = 0;
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

void error_msg(std::initializer_list<std::string> il) {
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}

void mySwap2(int& a, int& b) {
	std::cout << "before swap a is " << a << " b is " << b << std::endl;
	int t = a;
	a = b;
	b = t;
	std::cout << "after swap a is " << a << " b is " << b << std::endl;
}

int calc_sum(const std::initializer_list<int>& x) {
	int sum = 0;
	for (auto it = x.begin(); it != x.end(); ++it) {
		sum += *it;
	}
	return sum;
}

int main() {
	int a = 3, b = 5;
	mySwap2(a, b);
	
	int sum = calc_sum({1, 2, 3, 4, 5, 6, 7, 8, 9});
	std::cout << sum << std::endl;
	
	return 0;
}


//int main() {
//	interactive_act();
//
//	return 0;
//}