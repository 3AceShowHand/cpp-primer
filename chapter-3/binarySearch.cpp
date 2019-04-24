//
// Created by king on 2019/4/20.
//

#include <vector>
#include <iostream>

int binarySearch(const std::vector<int>& x, int sought) {
	auto begin = x.cbegin();
	auto end = x.cend();
	auto mid = begin + (end - begin) / 2;
	while (mid != end && *mid != sought) {
		if (sought < *mid) {
			end = mid;
		} else {
			begin = mid;
		}
		mid = begin + (end - begin) / 2;
	}
	return mid - x.cbegin();
}

int main() {
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	int idx = binarySearch(vec, 2);
	std::cout << idx << std::endl;
	
	return 0;
}
