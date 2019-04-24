//
// Created by king on 2019/4/22.
//

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> v) {
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec;
	vector<int> vec2(10);
	vector<int> vec3(10, 1);
	vector<int> vec4{1, 2, 3, 4, 5};
	vector<int> vec5(vec4);
	vector<int> vec6(vec3.cbegin() + 3, vec3.cend());
	
	printVector(vec);
	printVector(vec2);
	printVector(vec3);
	printVector(vec4);
	printVector(vec5);
	printVector(vec6);
	
	
	return 0;
}