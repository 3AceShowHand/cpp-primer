//
// Created by king on 2019/4/20.
//

#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main() {
	int local_int;
	std::string local_str;
	
	std::cout << "global_str default is :" << global_str << std::endl;
	std::cout << "global_int default is :" << global_int << std::endl;
	
	std::cout << "local_int default is: " << local_int << std::endl;
	std::cout << "local_str default is: " << local_str << std::endl;
	
	
	return 0;
}