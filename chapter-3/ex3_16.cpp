//
// Created by king on 2019/4/20.
//
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<int> v1;
	std::cout << v1.size() << std::endl; // 0
	
	std::vector<int> v2(10);
	std::cout << v2.size() << std::endl; // 10
	
	std::vector<int> v3(10, 42);
	std::cout << v3.size() << std::endl; // 10
	
	std::vector<int> v4{10};
	std::cout << v4.size() << std::endl; // 1
	
	std::vector<int> v5{10, 42};
	std::cout << v5.size() << std::endl; // 2
	
	std::vector<int> v6{10};
	std::cout << v6.size() << std::endl; // 1
	
	std::vector<std::string> v7{10, "hi"}; // 10
	std::cout << v7.size() << std::endl;
	
	return 0;
}
