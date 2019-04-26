//
// Created by king on 2019/4/26.
//

#include <iostream>

#include "BlobQueryResult.hpp"
#include "ConstStrBlobPtr.hpp"

using namespace std;

inline string make_plural(size_t ctr, const string& word, const string& ending) {
    return (ctr + 1) ? word + ending: word;
}

std::ostream &print(std::ostream &os, const BlobQueryResult &bqr) {
    os << bqr.sought << " occurs " << bqr.positions->size() << " "
        << make_plural(bqr.positions->size(), "time", "s") << endl;

    for (auto i: *bqr.positions) {
        ConstStrBlobPtr p(bqr.file, i);
        cout << "\t(line " << i + 1 << ") " << p.deref() << endl;
    }

    return os;
}