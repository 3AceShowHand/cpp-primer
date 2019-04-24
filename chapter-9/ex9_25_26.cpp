//
// Created by king on 2019/4/22.
//

#include <vector>
#include <list>
#include <iostream>

using namespace std;

void func9_26() {
	
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	
	vector<int> v(begin(ia), end(ia));
	list<int> l(begin(ia), end(ia));
	
	auto it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0) {
			it = v.erase(it);
		} else {
			it++;
		}
	}
	auto it2 = l.begin();
	while (it2 != l.end()) {
		if (*it2 % 2 == 1) {
			it2 = l.erase(it2);
		} else {
			it2++;
		}
		
	}
	
	cout << "vector without even" << endl;
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "list without odd" << endl;
	for (auto it = l.cbegin(); it != l.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}


int main() {
	vector<int> s = {1, 2, 3, 4, 5};
	cout << "origin s: " << endl;
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "erase both at begin: " << endl;
	s.erase(s.begin(), s.begin());
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "erase both at end: " << endl;
	s.erase(s.end(), s.end());
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "erase from begin to end: " << endl;
	s.erase(s.begin(), s.end());
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	func9_26();
	
	return 0;
}