//
// Created by king on 2019/4/22.
//

#include <vector>
#include <iostream>
#include <array>
#include <list>
#include <string>

using namespace std;


int main() {
	
	array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	array<int, 10> a2 = {0};
	a1 = a2;
	
	list<string> names{"Ling Jin", "Yaqiang Wu", "Housheng Wei", "Lei Wan", "Hao Liu", "Jie Liu"};

	vector<string> svec1(10);
	vector<string> svec2(24);
	swap(svec1, svec2);
	
	vector<int> v1 = {1, 3, 5, 7, 9, 12};
	vector<int> v2 = {1, 3, 9};
	vector<int> v3 = {1, 3, 5, 7};
	vector<int> v4 = {1, 3, 5, 7, 9, 12};
	
	cout << (v1 < v2) << endl;
	cout << (v1 < v3) << endl;
	cout << (v1 == v4) << endl;
	cout << (v1 == v2) << endl;
	
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	auto it = lst.begin();
	while (it != lst.end()) {
		if (*it % 2) {
			it = lst.erase(it);
		} else {
			++it;
		}
	}
	
	for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	
	return 0;
}