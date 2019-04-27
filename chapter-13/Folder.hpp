//
// Created by king on 2019/4/27.
//

#ifndef CPP_PRIMER_FOLDER_HPP
#define CPP_PRIMER_FOLDER_HPP

#include <set>

class Message;
class Folder {
    friend class Message;
    friend void swap(Folder& lhs, Folder& rhs);

public:

    Folder() = default;
    Folder(const Folder& f);
    Folder& operator=(const Folder& f);

    ~Folder();

    void print_debug();

private:

    std::set<Message*> messages;

    void add_to_message(const Folder& f);
    void remove_from_message();

    void addMsg(Message* m);
    void remMsg(Message* m);
};

inline void swap(Folder& lhs, Folder& rhs) {
    using std::swap;

    lhs.remove_from_message();
    rhs.remove_from_message();

    swap(lhs.messages, rhs.messages);

    lhs.add_to_message(lhs);
    rhs.add_to_message(rhs);
}


#endif