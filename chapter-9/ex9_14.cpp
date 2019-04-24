//
// Created by king on 2019/4/22.
//

#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main() {
	
	list<char *> names {"LingJin", "Jie Liu"};
	vector<string> newNames;
	
	newNames.assign(names.cbegin(), names.cend());
	for (auto it = newNames.cbegin(); it != newNames.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}