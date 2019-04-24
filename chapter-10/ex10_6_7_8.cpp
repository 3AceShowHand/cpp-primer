//
// Created by king on 2019/4/22.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void func10_7_1() {
	vector<int> vec;
	list<int> lst{1, 2, 3, 4, 5};
	
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
	for (const auto& item: vec) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	
	vector<int> v1{1, 2, 3, 4, 5, 6, 7};
	fill_n(v1.begin(), v1.size(), 0);
	for (const auto& item: v1) {
		cout << item << " ";
	}
	cout << endl;
	
	func10_7_1();
	
	return 0;
}