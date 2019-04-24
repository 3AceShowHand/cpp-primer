//
// Created by king on 2019/4/23.
//

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

 bool check_size(const string& s, string::size_type sz) {
	 return s.size() > sz;
 }
 
 int func10_22(const vector<string>& words) {
	 return count_if(words.begin(), words.end(), bind(check_size, placeholders::_1, 6));
 }
 
 int func10_24(const vector<int>& v, const string& s) {
	 auto it = find_if_not(v.cbegin(), v.cend(), bind(check_size, s, placeholders::_1));
	 return *it;
 }
 
 void biggies(vector<string>& words, vector<string>::size_type sz) {
 	sort(words.begin(), words.end());
 	words.erase(unique(words.begin(), words.end()), words.end());
 	auto iter = stable_partition(words.begin(), words.end(),
 			bind(check_size, placeholders::_1, sz));
 	for_each(words.begin(), iter, [](const string& s) {
 		std::cout << s << " ";
 	});
 }
 
 
int main() {
	vector<string> words = {"fuckyou", "shit", "wtf", "ComputerScience", "Software", "Ling", "QT", "GuoJiaQiao",
						 "Natural", "Language", "Computer", "vision"};
	int ret1 = func10_22(words);
	cout << ret1 << endl;
	
	vector<int> v{1, 2, 3, 4, 5};
	int ret2 = func10_24(v, "shit");
	cout << ret2 << endl;
	
	vector<string> words2{"the","quick", "red", "fox", "jumps", "over",
				  "the", "slow", "red", "turtle"};
	biggies(words2, 4);
	
	return 0;
}