//
// Created by king on 2019/4/27.
//

#include <iostream>

using namespace std;

class bulk_item {

public:
    bulk_item(int val): x(val) {

    }

    bulk_item(const bulk_item& rhs) {
        cout << "!!!" << endl;
        x = rhs.x;
    }

private:

    int x;
};

int main(int argc, char* argv[]) {
    bulk_item a = bulk_item(10);

    bulk_item* x = new bulk_item(5);
    delete x;

    return 0;
}