//
// Created by king on 2019/4/22.
//

#include <iostream>

using namespace std;

auto sum = [] (int a, int b) {
	return a + b;
};


int main() {
	int ret = sum(1, 2);
	cout << ret << endl;
	
	auto ret2 = [ret](int sum) {
		return ret + sum;
	};
	
	ret = ret2(5);
	cout << ret << endl;
	
	return 0;
}