//
// Created by king on 2019/4/25.
//

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void func12_6_input(const string& filename, vector<int>* vptr) {
    ifstream ifs(filename);
    int num;
    if (ifs) {
        while (ifs >> num) {
            vptr->push_back(num);
        }
    }
}

void func12_6_output(vector<int>* vptr) {
    for (auto iter = vptr->cbegin(); iter != vptr->cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    delete vptr;
}

void func12_7_input(const string& filename, shared_ptr<vector<int>> v1) {
    ifstream ifs(filename);
    int num;
    if (ifs) {
        while (ifs >> num) {
            v1->push_back(num);
        }
    }
}

void func12_7_output(shared_ptr<vector<int>> v1) {
    for (const auto& item : *v1) {
        cout << item << " ";
    }
    cout << endl;
}


int main() {
    auto v = new vector<int>();
    func12_6_input("../data/ints.txt", v);
    func12_6_output(v);

    auto v1 = make_shared<vector<int>>();
    func12_7_input("../data/ints.txt", v1);
    func12_7_output(v1);

    return 0;
}
