//
// Created by king on 2019/4/22.
//

#include <string>
#include <list>
#include <deque>
#include <fstream>
#include <iostream>

using namespace std;

deque<string> func1(const string& filename) {
	fstream infile(filename);
	deque<string> ret;
	string buf;
	while (infile >> buf) {
		ret.push_back(buf);           // this is the key difference
	}
	
	return ret;
}

list<string> func2(const string& filename) {
	fstream infile(filename);
	list<string> ret;
	string buf;
	while (infile >> buf) {
		ret.insert(ret.begin(), buf);  // this is the key difference.
	}
	return ret;
}

void func3(const list<int> list, deque<int>& even, deque<int>& odd) {
	for (auto it = list.cbegin(); it != list.cend(); ++it) {
		if (*it % 2 == 0) {
			even.push_back(*it);
		} else {
			odd.push_back(*it);
		}
	}
}


int main() {
	cout << "store by deque" << endl;
	auto ret1 = func1("../data/letter.txt");
	for (auto it = ret1.cbegin(); it != ret1.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "store by list" << endl;
	auto ret2 = func2("../data/letter.txt");
	for (auto it = ret2.cbegin(); it != ret2.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 0};
	deque<int> even, odd;
	func3(l, even, odd);
	
	cout << "origin input list: " << endl;
	for (auto it = l.cbegin(); it != l.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "even deque: " << endl;
	for (auto it = even.cbegin(); it != even.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "odd deque: " << endl;
	for (auto it = odd.cbegin(); it != odd.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}