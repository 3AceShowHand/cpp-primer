//
// Created by king on 2019/4/22.
//

#include <forward_list>
#include <string>
#include <iostream>
using namespace std;

void func9_28(forward_list<string>& flst, const string& first, const string& second) {
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr == first) {
			break;
		}
		prev = curr;
		++curr;
	}
	if (curr != flst.end()) {
		flst.insert_after(curr, second);
	} else {
		flst.insert_after(prev, second);
	}
}


int main() {
	
	forward_list<string> flst1 = {"hello", "halo", "world", "test"};
	cout << "before insert: " << endl;
	for (auto iter = flst1.cbegin(); iter != flst1.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "insert by find :" << endl;
	func9_28(flst1, "halo", "fuck");
	for (auto iter = flst1.cbegin(); iter != flst1.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	cout << "insert by not find: " << endl;
	func9_28(flst1, "not", "fuck");
	for (auto iter = flst1.cbegin(); iter != flst1.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}
	for (auto iter = flst.cbegin(); iter != flst.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout <<endl;
	
	return 0;
}