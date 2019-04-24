//
// Created by king on 2019/4/22.
//

#include <vector>

class Example {
public:
	static double rate;
	// static double rate;
	
	static const int vecSize = 20;
	// static const int vecSize;
	// static std::vector<double> vec(vecSize);
	
	static std::vector<double> vec;
	
};

double Example::rate = 6.5;
std::vector<double> Example::vec(vecSize);