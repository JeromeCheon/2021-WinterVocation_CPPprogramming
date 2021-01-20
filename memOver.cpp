#include <iostream>

using namespace std ;

class testclass{
public:
	testclass() : data(0) { }

	int getter(void) { return data ;}
	void setter(int param) { data = param ;}

	void setter(double param) {data = 0 ;}

private:
	int data ;
};

int main(void){
	testclass a, b ;
	a.setter(10) ;
	cout << a.getter() << endl ;
	b.setter(1.1) ;
	cout << b.getter() << endl ;
	return 0 ;
}
