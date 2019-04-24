//
// Created by king on 2019/4/23.
//

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

list<int> copyUniqueFromVector(const vector<int>& v) {
	list<int> ret;
	unique_copy(v.cbegin(), v.cend(), back_inserter(ret));
	
	return ret;
}

int main() {
	vector<int> orig{1, 1, 2, 3, 4, 4, 5};
	list<int> l = copyUniqueFromVector(orig);
	for (const auto& item: l) {
		cout << item << " ";
	}
	cout << endl;
	
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> front, back, inser;
	
	copy(v.cbegin(), v.cend(), front_inserter(front));
	for (const auto& item: front) {
		cout << item << " ";
	}
	cout << endl;
	
	copy(v.cbegin(), v.cend(), back_inserter(back));
	for (const auto& item: back) {
		cout << item << " ";
	}
	cout << endl;
	
	copy(v.cbegin(), v.cend(), inserter(inser, inser.begin()));
	for (const auto& item: inser) {
		cout << item << " ";
	}
	cout << endl;
	
	return 0;
}
