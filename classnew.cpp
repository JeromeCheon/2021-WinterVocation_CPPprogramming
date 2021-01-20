#include <iostream>

using namespace std ;

class test{
	int data ;
public:
	test(){
		cout << "start test() constructor" << endl ;
	}

	~test(){
		cout << "test() destructor" << endl ;
	}
};

int main(){
	test* pdata = new test[3] ;
	cout << "begin" << endl ;
	delete[] pdata ;
	cout << "end" << endl ;

	return 0;
}
