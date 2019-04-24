//
// Created by king on 2019/4/21.
//

#include <string>

typedef std::string Type;
Type initVal();

class Exercise {

public:
	
	typedef double Type;
	Type setVal(Type);
	Type initVal();

private:
	int val;
};

Exercise::Type Exercise::setVal(Exercise::Type param) {
	val = param + initVal();
	return val;
}

int main() {
	return 0;
}