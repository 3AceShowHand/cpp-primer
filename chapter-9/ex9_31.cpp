//
// Created by king on 2019/4/22.
//
#include <vector>
#include <list>
#include <forward_list>
#include <iostream>

using namespace std;

void func() {
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "before processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
	
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter += 2;
		} else {
			iter = vi.erase(iter);
		}
	}
	
	cout << "after processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
}

void func2() {
	vector<int> v{2, 3, 4, 5, 6};
	auto begin = v.begin();
	while (begin != v.end()) {
		++begin;
		begin = v.insert(begin, 42);
		++begin;
	}
	
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
}

void func9_31() {
	list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "before processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
	
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;
		} else {
			iter = vi.erase(iter);
		}
	}
	
	cout << "after processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
}

void func9_31_2() {
	forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "before processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
	
	auto prev = vi.before_begin();
	auto curr = vi.begin();
	
	while (curr != vi.end()) {
		if (*curr % 2 == 0) {
			curr = vi.erase_after(prev);
		} else {
			curr = vi.insert_after(prev, *curr);
			advance(curr, 2);
			advance(prev, 2);
		}
	}
	
	cout << "after processing: " << endl;
	for (const auto& item: vi) {
		cout << item << " ";
	}
	cout << endl;
}



int main() {
	
//	func();
	
	func2();
	
//	func9_31();
//
//	func9_31_2();
	
	return 0;
}
