#include <iostream>

using namespace std ;

class testclass{
public:
	testclass(int nparam) : data(nparam) {} ;
	void printData(){
		cout << data << endl ;

		cout << testclass::data << endl ;

		cout << this->data << endl ;

		cout << this->testclass::data << endl ;
	}

private:
	int data ;
};

int main(void){
	testclass a(5), b(10) ;
	a.printData() ;
	b.printData() ;

	return 0 ;
}

