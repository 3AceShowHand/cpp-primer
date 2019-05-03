//
// Created by king on 2019/5/1.
//


#include <iostream>
#include "Quote.hpp"
#include "Bulk_quote.hpp"
#include "Special_quote.hpp"


using namespace std;


double print_total(ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

    return ret;
}

int main() {

    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2 = std::move(bq2);

    return 0;
}