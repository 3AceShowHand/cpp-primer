//
// Created by king on 2019/4/22.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getStringFromVector(const vector<char>& v) {
	return string(v.begin(), v.end());
}


int main() {
	vector<char > v = {'H', 'a', 'l', 'o'};
	string ret = getStringFromVector(v);
	
	cout << ret << endl;
	
	return 0;
}