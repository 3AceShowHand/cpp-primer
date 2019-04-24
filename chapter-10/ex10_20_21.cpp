//
// Created by king on 2019/4/23.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int func10_20(const vector<string>& words) {
	return count_if(words.cbegin(), words.cend(),
			[](const string& w) {
				return w.size() > 6;
			});
}

void func10_21(int a) {
	auto f = [&a]() -> bool {
		if (a != 0) return !--a;
		else return true;
	};
	while (a != 0) {
		cout << "a is " << a << endl;
		f();
	}
}


int main() {
	
	vector<string> words = {"LingJin", "LeiWan", "halo", "faker", "fuck", "scu", "ComputerScience"};
	
	int ret1 = func10_20(words);
	cout << ret1 << endl;
	
	func10_21(10);
	
	return 0;
}