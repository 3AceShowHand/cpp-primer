//
// Created by king on 2019/4/21.
//

#include <string>
#include <iostream>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

int main() {
	std::string word1 = "success";
	std::string word2 = "failure";
	
	std::string res1 = make_plural(2, word1, "es");
	std::cout << res1 << std::endl;
	
	std::string res2 = make_plural(2, word2);
	std::cout << res2 << std::endl;
	
	return 0;
}