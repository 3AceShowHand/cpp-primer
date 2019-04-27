//
// Created by king on 2019/4/27.
//

#include <iostream>
#include "Folder.hpp"
#include "Message.hpp"


Folder::Folder(const Folder &f): messages(f.messages) {
    add_to_message(f);
}

Folder &Folder::operator=(const Folder &f){
    remove_from_message();
    messages = f.messages;
    add_to_message(f);

    return *this;
}

Folder::~Folder() {
    remove_from_message();
}

void Folder::print_debug() {

    for (auto m: messages) {
        std::cout << m->getContent() << std::endl;
    }

    std::cout << std::endl;
}

void Folder::remove_from_message() {
    for (auto m: messages) {
        m->remFolder(this);
    }
}

void Folder::add_to_message(const Folder& f) {
    for (auto m: messages) {
        m->addFolder(this);
    }
}

void Folder::addMsg(Message *m) {
    this->messages.insert(m);
}

void Folder::remMsg(Message *m) {
    this->messages.erase(m);
}

