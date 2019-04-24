//
// Created by king on 2019/4/22.
//

#include <vector>
#include <iostream>

using namespace std;

bool find_int(vector<int>::const_iterator first, vector<int>::const_iterator second, int target) {
	while (first != second) {
		if (*first == target) {
			return true;
		}
		++first;
	}
	
	return false;
}

vector<int>::const_iterator find_int_iter(vector<int>::const_iterator first, vector<int>::const_iterator second, int target) {
	while (first != second) {
		if (*first == target) {
			return first;
		}
		++first;
	}
	return first;
}



int main() {
	vector<int> v{1, 2, 3, 4, 5};
	
	auto find1 = find_int(v.cbegin(), v.cend(), 3);
	auto find2 = find_int(v.begin(), v.end(), 7);
	
	cout << find1 << endl;
	cout << find2 << endl;
	
	auto find_iter1 = find_int_iter(v.begin(), v.end(), 3);
	auto find_iter2 = find_int_iter(v.begin(), v.end(), 7);
	
	cout << *find_iter1 << endl;
	cout << *find_iter2 << endl;
	
	
	return 0;
}
