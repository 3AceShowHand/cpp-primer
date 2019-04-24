//
// Created by king on 2019/4/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	vector<int> v1{1, 2, 3, 4, 5, 1, 1, 1, 1, 2, 3, 4, 5, 4, 2, 3, 5, 7, 7,5, 1};
	int ret1 = count(v1.cbegin(), v1.cend(), 1);
	cout << ret1 << endl;
	
	list<string> v2 {"hello", "world", "halo", "hello", "Hello", "WORLD", "haaha"};
	int ret2 = count(v2.cbegin(), v2.cend(), "hello");
	cout << ret2 << endl;
	
	
	return 0;
}
