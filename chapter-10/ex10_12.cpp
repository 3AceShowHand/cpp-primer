//
// Created by king on 2019/4/22.
//


#include <vector>
#include <algorithm>

#include "Sales_data.h"

using namespace std;


int main() {
	Sales_data d1("aa"), d2("aaa"), d3("aaaa"), d4("z"), d5("aaaaz");
	vector<Sales_data> v{d1, d2, d3, d4, d5};
	
	sort(v.begin(), v.end(), compareIsbn);
	
	for (const auto& item : v) {
		cout << item.isbn() << " ";
	}
	cout << endl;
	
	return 0;
}