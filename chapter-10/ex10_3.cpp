//
// Created by king on 2019/4/22.
//

#include <numeric>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	// 10.3
	vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << sum << endl;
	
	// 10.4
	vector<double> v2{3.14, 3.15, 1.4141, 1.723, 2.71};
	double sum2 = accumulate(v2.cbegin(), v2.cend(), 0.0);
	cout << sum2 << endl;
	
	return 0;
}
