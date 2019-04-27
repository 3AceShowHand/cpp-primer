//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_NUMBERED_HPP
#define CPP_PRIMER_NUMBERED_HPP


class numbered {

public:
    numbered();

    numbered(const numbered& x);

    int getMysn() const {
        return mysn;
    }

private:

    static int sn_manager;
    int mysn;

};
int numbered::sn_manager = 0;



#endif //CPP_PRIMER_NUMBERED_HPP
