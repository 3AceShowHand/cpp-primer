//
// Created by king on 2019/4/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Sales_data.h"


using namespace std;

vector<string> ex8_4(const string& filename) {
	ifstream ifs(filename);
	vector<string> ret;
	if (ifs) {
		string buf;
		while (getline(ifs, buf)) {
			ret.push_back(buf);
		}
	}
	return ret;
}

vector<string> ex8_5(const string& filename) {
	ifstream ifs(filename);
	vector<string> ret;
	if (ifs) {
		string buf;
		while (ifs >> buf) {
			ret.push_back(buf);
		}
	}
	return ret;
}


int main(int argc, char* argv[]) {
	vector<string> v = ex8_4("../data/book.txt");
	for (const auto& item: v) {
		cout << item << endl;
	}
	
	vector<string> v2 = ex8_5("../data/book.txt");
	for (const auto& item : v2) {
		cout << item << endl;
	}
	
	if (argc != 3) {
		cerr << "please given a filename for books" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if (input >> total) {
		Sales_data trans;
		while (input >> trans) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				output << total << endl;
				total = trans;
			}
		}
		output << total << endl;
	} else  {
		cerr << "No data?!" << endl;
	}
	
	return 0;
}