//
// Created by king on 2019/4/21.
//

#ifndef CPP_PRIMER_WINDOW_MGR_HPP
#define CPP_PRIMER_WINDOW_MGR_HPP

#include <vector>
#include "Screen.hpp"

class Window_mgr {

public:
	using ScreenIndex = std::vector<Screen>::size_type ;
	
	void clear(ScreenIndex idx);
	
	ScreenIndex addScreen(const Screen& s);

private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
	
};


#endif //CPP_PRIMER_WINDOW_MGR_HPP
