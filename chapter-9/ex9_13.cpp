//
// Created by king on 2019/4/22.
//

#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	
	list<int> l{1, 2, 3, 4, 5, 6, 7};
	// vector<double> vv(l); different container type and element type.
	vector<double> v(l.cbegin(), l.cend());
	
	vector<int> v2{1, 2, 3, 4, 5};
	// vector<double> v3(v2);    cannot construct v3 by v2, since different element type
	vector<double> v3(v2.cbegin(), v2.cend());
	
	return 0;
}
