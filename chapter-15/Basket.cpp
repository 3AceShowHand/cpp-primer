//
// Created by king on 2019/5/3.
//

#include "Basket.hpp"

double print_total(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
       << std::endl;

    return ret;
}

double Basket::total_receipt(std::ostream& os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend();
         iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total sale: " << sum << std::endl;

    return sum;
}

void Basket::add_item(const std::shared_ptr<Quote>& sale) {
    items.insert(sale);
}

void Basket::add_item(Quote&& sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    std::cout << "Basket::add_item(Quote && sale)" << std::endl;
}

void Basket::add_item(const Quote& sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
    std::cout << "Basket::add_item(const Quote& sale)" << std::endl;
}
