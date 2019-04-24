//
// Created by king on 2019/4/21.
//

class Y;

class X {
private:
	Y* ptr;
};

class Y {
private:
	X bar;
};

int main() {
	X x;
	Y y;
	
	return 0;
}