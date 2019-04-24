//
// Created by king on 2019/4/24.
//


#include <map>
#include <string>
#include <iostream>

using namespace std;


int main() {

    multimap<string, string> books;
    books.insert({"村上春树", "挪威的森林"});
    books.insert({"村上春树", "舞舞舞"});
    books.insert({"村上春树", "海边的卡夫卡"});
    books.insert({"村上春树", "寻羊历险记"});
    books.insert({"东野圭吾", "白夜行"});
    books.insert({"东野圭吾", "嫌疑人X的献身"});
    books.insert({"东野圭吾", "解忧杂货店"});

    cout << "first method" << endl;
    auto entries = books.count(string("村上春树"));
    auto iter = books.find("村上春树");
    while (entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
    cout << endl;

    cout << "second method" << endl;
    auto begin = books.lower_bound(string("村上春树"));
    auto end = books.upper_bound(string("村上春树"));
    while (begin!= end) {
        cout << begin->second << endl;
        ++begin;
    }
    cout << endl;

    cout << "third method" << endl;
    for (auto pos = books.equal_range(string("村上春树")); pos.first != pos.second; ++pos.first) {
        cout << pos.first->second << endl;
    }
    cout << endl;

    // what will be returned, if the key not in the map
    auto key = string("bjarne");
    auto lower = books.lower_bound(key);
    cout << lower->first << " " << lower->second << endl;

    auto upper = books.upper_bound(key);
    cout << upper->first << " " << upper->second << endl;

    auto range = books.equal_range(key);
    cout << range.first->second << endl;
    cout << range.second->second << endl;

    for (auto begin = books.cbegin(); begin != books.cend(); ++begin) {
        cout << begin->first << " " << begin->second << endl;
    }

    return 0;
}