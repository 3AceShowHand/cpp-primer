//
// Created by king on 2019/5/2.
//

#include <string>
#include <iostream>

using namespace std;

class base {
public:
    string name() {
        return basename;
    }

    virtual void print(ostream& os = cout) {
        os << basename;
    }

private:
    string basename;

};

class derived: public base {
public:
    void print(ostream& os=cout) override {
        base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main() {
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;

    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    bobj.print();
    dobj.print();
    bp1->name();

    bp2->name();
    br1.print();
    br2.print();

    return 0;

}