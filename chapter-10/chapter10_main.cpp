//
// Created by king on 2019/4/22.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& v) {
	for (const auto& item: v) {
		cout << item << " ";
	}
	cout << endl;
}

void elimDups(vector<string>& words) {
	for (const auto& item : words) {
		cout << item << " ";
	}
	cout << endl;
	sort(words.begin(), words.end());
	for (const auto& item : words) {
		cout << item << " ";
	}
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	for (const auto& item : words) {
		cout << item << " ";
	}
	cout << endl;
}


int main() {
	
	// back_inserter
	vector<int> vec;
	auto it = back_inserter(vec);
	*it = 42;
	printVector(vec);
	
	fill_n(it, 10, 0);
	printVector(vec);
	
	// copy
	int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int a2[sizeof(a1) / sizeof(*a1)];
	copy(begin(a1), end(a1), a2);
	
	// sort and unique
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(words);
	
	
	
	return 0;
}