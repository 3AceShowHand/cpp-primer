//
// Created by king on 2019/4/22.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void elimDups(vector<string>& words) {
//	for (const auto& item : words) {
//		cout << item << " ";
//	}
//	cout << endl;
	sort(words.begin(), words.end());
//	for (const auto& item : words) {
//		cout << item << " ";
//	}
//	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
//	for (const auto& item : words) {
//		cout << item << " ";
//	}
//	cout << endl;
}

bool isShorter(const string& str1, const string& str2) {
	return str1.size() < str2.size();
}

inline
string make_plural(size_t ctr, const string &word,
                   const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
		return a.size() < b.size();
	});
	
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {
		return a.size() > sz;
	});
	
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;
}



int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(words, 7);
	
	return 0;
}
