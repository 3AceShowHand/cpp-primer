//
// Created by king on 2019/4/21.
//

#include "Window_mgr.hpp"

void Window_mgr::clear(Window_mgr::ScreenIndex idx) {
	auto s = screens[idx];
	s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
	this->screens.push_back(s);
	return screens.size() - 1;
}
