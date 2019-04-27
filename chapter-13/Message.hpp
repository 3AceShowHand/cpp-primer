//
// Created by king on 2019/4/27.
//

#ifndef CPP_PRIMER_MESSAGE_HPP
#define CPP_PRIMER_MESSAGE_HPP

#include <string>
#include <set>

class Folder;
class Message {

    friend class Folder;
    friend void swap(Message& lhs, Message& rhs);

public:
    explicit Message(const std::string& str=""): content(str) {
    }

    Message(const Message& m);

    Message& operator=(const Message& m);

    ~Message();

    void save(Folder& f);
    void remove(Folder& f);

    void addFolder(Folder* f);
    void remFolder(Folder* f);

    void print_debug();

    std::string getContent() const {
        return content;
    }

private:
    std::string content;
    std::set<Folder*> folders;

    void add_to_Folders(const Message& m);
    void remove_from_Folders();

};

inline void swap(Message& lhs, Message& rhs) {
    using std::swap;

    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.content, rhs.content);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

#endif //CPP_PRIMER_MESSAGE_HPP
