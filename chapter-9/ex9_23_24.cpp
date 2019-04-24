//
// Created by king on 2019/4/22.
//

#include <vector>
#include <iostream>

using namespace std;


void func9_23() {
	vector<int> c = {1};
	if (!c.empty()) {
		auto val1 = *c.begin(), val2 = c.front();
		cout << "val1 is " << val1 << endl;
		cout << "val2 is " << val2 << endl;
		
		auto last = c.end();
		auto val3 = *(--last);
		cout << "val3 is " << val3 << endl;
		
		auto val4 = c.back();
		cout << "val4 is " << val4 << endl;
	}
}

void func9_24() {
	vector<int> v;
	
	cout << v.at(0) << endl; // std::out_of_range
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << *v.begin() << endl;
}



int main() {
	
	func9_23();
	func9_24();
	
	return 0;
}