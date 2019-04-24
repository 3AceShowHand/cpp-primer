//
// Created by king on 2019/4/21.
//

#include "Screen.hpp"

char Screen::get(Screen::pos ht, Screen::pos wd) const {
	pos row = ht * width;
	return contents[row +  wd];
}

Screen &Screen::move(Screen::pos r, Screen::pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

Screen &Screen::set(Screen::pos r, Screen::pos c, char ch) {
	pos p = r * width + c;
	contents[p] = ch;
	
	return *this;
}

Screen::pos Screen::size() const {
	return height * width;
}

