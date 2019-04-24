//
// Created by king on 2019/4/22.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline bool less_5(const string& s) {
	return s.size() > 5;
}

int main() {
	vector<string> strs{"hello", "world", "halo", "fuck", "shit", "orange", "black", "trump", "aha", "GreenTea"};
	
	auto partition_end = partition(strs.begin(), strs.end(), less_5);
	for (const auto& item : strs) {
		cout << item << " ";
	}
	cout << endl;
	
	strs.erase(partition_end, strs.end());
	for (const auto& item : strs) {
		cout << item << " ";
	}
	cout << endl;
	
	return 0;
}