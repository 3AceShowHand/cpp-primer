//
// Created by king on 2019/5/1.
//


#include <iostream>
#include "Quote.hpp"
#include "Bulk_quote.hpp"

using namespace std;

double print_total(ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

    return ret;
}


int main() {

    Quote basic;
    Bulk_quote bulk;

    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);

    return 0;
}