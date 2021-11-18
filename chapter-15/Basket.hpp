//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_BASKET_HPP
#define CPP_PRIMER_BASKET_HPP

#include "Quote.hpp"
#include <memory>
#include <set>

class Basket {

  public:
    Basket() {
        std::cout << "Basket()" << std::endl;
    }

    void add_item(const std::shared_ptr<Quote>& sale);

    void add_item(const Quote& sale);
    void add_item(Quote&& sale);

    double total_receipt(std::ostream& os) const;

  private:
    static bool compare(const std::shared_ptr<Quote>& lhs,
                        const std::shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif // CPP_PRIMER_BASKET_HPP
