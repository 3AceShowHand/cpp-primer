//
// Created by king on 2019/4/20.
//

#include <iostream>
#include <string>

void printPunctual(const std::string& s) {
	decltype(s.size()) cnt = 0;
	
	for (auto c: s) {
		if (ispunct(c)) {
			cnt += 1;
		}
	}
	std::cout << cnt <<" punctuation characters in " << s << std::endl;
}

int main() {
	std::string s{"hello, world?!"};
	printPunctual(s);
	
	return 0;
	
}

//int main() {
//	std::string str, res;
//	while (std::cin >> str) {
//		if (!str.empty()) {
//			res = res + " " + str;
//		} else {
//			break;
//		}
//	}
//	std::cout << res << std::endl;
//
//	return 0;
//}