//
// Created by king on 2019/4/25.
//

#include <iostream>
#include <fstream>
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

using namespace std;

int main() {

    StrBlob sb;
    ifstream ifs("../data/line.txt");
    if (ifs) {
        string word;
        while (ifs >> word) {
            sb.push_back(word);
        }
    }

    for (StrBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg != pend; pbeg.inc()) {
        std::cout << pbeg.deref() << std::endl;
    }

    return 0;
}
