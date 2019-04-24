//
// Created by king on 2019/4/23.
//

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void fcn1() {
	size_t v1 = 42;
	auto f = [v1] { // capture by value
		return v1;
	};
	v1 = 0;
	auto j = f();
	cout << "j is : " << j << endl;
}

void fcn2() {
	size_t v1 = 42;
	auto f2 = [&v1] {
		return v1;
	};
	v1 = 0;
	auto j = f2();
	cout << "j is : " << j << endl;
}

// mutable lambda
void fcn3() {
	size_t v1 = 42;
	auto f2 = [v1] () mutable {
		return ++v1;
	};
	v1 = 0;
	auto j = f2();
	cout << "j is : " << j << endl;
}

void fcn4() {
	size_t v1 = 42;
	auto f2 = [&v1]  {
		return ++v1;
	};
	v1 = 0;
	auto j = f2();
	cout << "j is : " << j << endl;
}

int main() {
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	
	vector<int> v{-1, 2, -3, 4, -5};
	transform(v.begin(), v.end(), v.begin(), [](int i) {
		return i < 0 ? -i : i;
	});
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
	
	return 0;
}
