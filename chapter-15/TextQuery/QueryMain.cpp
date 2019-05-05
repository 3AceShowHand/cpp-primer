//
// Created by king on 2019/5/3.
//

#include <fstream>
#include <iostream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include "Query.hpp"
#include "NotQuery.hpp"
#include "OrQuery.hpp"
#include "AndQuery.hpp"

int main() {
    std::string filename("../data/query_text.txt");
    std::ifstream in(filename);
    TextQuery tq(in);

    Query q1("Alice");
    Query q2("Daddy");
    Query q3("her");
    Query q4("bird");

    Query nq = ~q1;
    Query aq = q1 & q3;
    Query oq = q2 | q4;
    Query qq = nq & oq | aq;

    std::cout << q1.eval(tq) << std::endl;
    std::cout << q2.eval(tq) << std::endl;
    std::cout << q3.eval(tq) << std::endl;
    std::cout << q4.eval(tq) << std::endl;

    std::cout << nq.eval(tq) << std::endl;
    std::cout << aq.eval(tq) << std::endl;
    std::cout << oq.eval(tq) << std::endl;
    std::cout << qq.eval(tq) << std::endl;


    return 0;
}