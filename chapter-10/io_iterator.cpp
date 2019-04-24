//
// Created by king on 2019/4/23.
//

#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

void example1() {
	istream_iterator<int> int_it(cin);
	istream_iterator<int> eof;
	
	vector<int> v1;
	while (int_it != eof) {
		v1.push_back(*int_it++);
	}
	for (const auto& item: v1) {
		cout << item << " ";
	}
	cout << endl;
}

void example2() {
	istream_iterator<int> in_iter(cin), eof;
	vector<int> v(in_iter, eof);
	
	for (const auto& item: v) {
		cout << item << " ";
	}
	cout << endl;
}

void example3() {
	istream_iterator<int> in(cin), eof;
	cout << accumulate(in, eof, 0) << endl;
}

// ostream iterator
void example4() {
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> v1 {3, 1, 4, 1, 5, 9, 2, 6};
	for (auto item: v1) {
		*out_iter++ = item;
	}
	cout << endl;
}

void example5() {
	vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};
	ostream_iterator<int> out_iter(cout, " ");
	copy(v.cbegin(), v.cend(), out_iter);
	cout << endl;
}


int main() {
	
	// example1();
	// example2();
	// example3();
	example4();
	
	example5();
	
	return 0;
}