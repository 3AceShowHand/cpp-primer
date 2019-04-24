//
// Created by king on 2019/4/22.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int strSumInt(const vector<string>& strs) {
	int sum = 0;
	for (const auto& item : strs) {
		sum += stoi(item);
	}
	
	return sum;
}

float strSumFloat(const vector<string>& strs) {
	float sum = 0;
	for (const auto& item: strs) {
		sum += stof(item);
	}
	
	return sum;
}

int main() {
	
	vector<string> strs = {"1", "2", "3", "4", "5"};
	
	cout << strSumInt(strs) << endl;
	cout << strSumFloat(strs) << endl;
	
	return 0;
}