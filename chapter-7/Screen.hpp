//
// Created by king on 2019/4/21.
//

#ifndef CPP_PRIMER_SCREEN_HPP
#define CPP_PRIMER_SCREEN_HPP

#include <string>


class Screen {
	
	typedef std::string::size_type pos;
	
	friend class Window_mgr;
	
public:
	
	Screen() = default;
	
	Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') {
	
	}
	
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) {
	
	}
	
	char get() const {
		return contents[cursor];
	}
	
	inline char get(pos ht, pos wd) const;
	
	Screen& set(char c);
	Screen& set(pos r, pos c, char ch);
	
	Screen& move(pos r, pos c) ;
	
	Screen& display(std::ostream& os) {
		do_display(os);
		return *this;
	}
	
	const Screen& display(std::ostream& os) const {
		do_display(os);
		return *this;
	}
	
	pos size() const;
	
	
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	void do_display(std::ostream& os) const {
		os << contents;
	}
	
	
	// using pos = std::string::size_type ;
};


#endif //CPP_PRIMER_SCREEN_HPP
