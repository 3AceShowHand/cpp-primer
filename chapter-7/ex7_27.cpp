//
// Created by king on 2019/4/21.
//

#include "Screen.hpp"
#include <iostream>

int main() {
	Screen myScreen(5, 5, 'X');
	
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << "\n";
	
	myScreen.display(std::cout);
	std::cout << "\n";
	
	const Screen screen2(3, 3, '*');
	screen2.display(std::cout);
	
	return 0;
}