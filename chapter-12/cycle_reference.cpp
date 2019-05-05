//
// Created by king on 2019/5/5.
//

#include <iostream>
#include <memory>

void func1() {
    std::cout << std::boolalpha << std::endl;

    auto sharedPtr=std::make_shared<int>(2011);
    std::weak_ptr<int> weakPtr(sharedPtr);

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;             // 1
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;        // 1
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;                  // false

    if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) {
        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;                               // 2011
        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;  // 2
    }
    else{
        std::cout << "Don't get the resource!" << std::endl;
    }

    weakPtr.reset();
    if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) {
        std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
        std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
    }
    else{
        std::cout << "Don't get the resource!" << std::endl;                  // this should be print
    }
    std::cout << std::endl;
}

struct Son;
struct Daughter;

struct Mother{
    ~Mother(){
        std::cout << "Mother gone" << std::endl;
    }
    void setSon(const std::shared_ptr<Son> s ){
        mySon=s;
    }
    void setDaughter(const std::shared_ptr<Daughter> d ){
        myDaughter=d;
    }
    std::weak_ptr<const Son> mySon;
    std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
    Son(std::shared_ptr<Mother> m):myMother(m){}
    ~Son(){
        std::cout << "Son gone" << std::endl;
    }
    std::shared_ptr<const Mother> myMother;
};

struct Daughter{
    Daughter(std::shared_ptr<Mother> m):myMother(m){}
    ~Daughter(){
        std::cout << "Daughter gone" << std::endl;
    }
    std::shared_ptr<const Mother> myMother;
};

int main(){
    std::cout << std::endl;
    std::shared_ptr<Mother> mother= std::shared_ptr<Mother>( new Mother);
    std::shared_ptr<Son> son= std::shared_ptr<Son>( new Son(mother) );
    std::shared_ptr<Daughter> daughter= std::shared_ptr<Daughter>( new Daughter(mother) );
    mother->setSon(son);
    mother->setDaughter(daughter);

    std::cout << std::endl;
}