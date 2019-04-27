//
// Created by king on 2019/4/27.
//

#include <iostream>
#include "Folder.hpp"
#include "Message.hpp"


Message::Message(const Message& m):content(m.content), folders(m.folders) {
    add_to_Folders(m);
}

Message& Message::operator=(const Message& m) {
    remove_from_Folders();
    content = m.content;
    folders = m.folders;
    add_to_Folders(m);

    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder& f) {
    addFolder(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    remFolder(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders) {
        f->addMsg(this);
    }

}

void Message::remove_from_Folders() {
    for (auto f: this->folders) {
        f->remMsg(this);
    }
}

void Message::addFolder(Folder *f) {
    f->remMsg(this);
    this->folders.insert(f);

}

void Message::remFolder(Folder* f) {
    f->addMsg(this);
    this->folders.insert(f);
}

void Message::print_debug() {
    std::cout << content << std::endl;
}