//
// Created by king on 2019/5/2.
//

#include <iostream>

using namespace std;

class base {
public:
    base() {
        a = 0;
        b = 1;
        c = 2;
    }
    int a;

protected:
    int b;
private:
    int c;
};

/* derived1, derived2, derived3 都是继承自 base。
 * 继承的方式与能否访问直接基类的成员没什么影响。
 * 因为在基类中 a 是 public，b 是 protected， 所以在派生类当中依旧可以访问。*/

class derived1: public base {
public:
    void func() {
        std::cout << base::a << base::b << std::endl;
    }
};

class derived2 : protected base {
    void func() {
        std::cout << base::a << base::b << std::endl;
    }
};

class derived3: private base {
    void func() {
        std::cout << base::a << base::b << std::endl;
    }
};

/* 因为 derived3是私有继承自base， 那么 base 这个基类在 derived3 当中是 private
 * 无论 a， b， c 在 base 当中是什么访问属性的，在derived3 当中都是 private的，所以
 * derived4 当中也是 private， 无法访问。*/
class derived4 : public derived3 {
    void func() {
        std::cout << derived3::a << derived3::b << derived3::c << endl;
    }
};

/* 因为 derived1 是公有继承自 base， 那么 base 在 derived1 当中是 public的，
 * derived1 的派生类当中可以访问这部分的内容。*/
class derived5: public derived1 {
    void func() {
        std::cout << derived1::a << derived1::b << std::endl;
    }
};