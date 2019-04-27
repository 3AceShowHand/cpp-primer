//
// Created by king on 2019/4/27.
//

#ifndef CPP_PRIMER_EMPLOYEE_HPP
#define CPP_PRIMER_EMPLOYEE_HPP

#include <string>

class Employee {

public:
    Employee() : number(number_manager++){

    }

    Employee(const std::string& name_): name(name_), number(number_manager++) {

    }

    Employee(const Employee&) = delete;

    Employee& operator=(const Employee&) = delete;


    std::string getName() const {
        return name;
    }

    int getNumber() const {
        return number;
    }


private:
    std::string name;
    int number;

    static int number_manager;

};

int number_manager = 0;


#endif //CPP_PRIMER_EMPLOYEE_HPP
