#include <iostream>
#include <string>
using namespace std ;
template <typename T>
T TestFunc(T a){
	cout << "매개 변수 a: " << a << endl ;

	return a ;
}

int main(){
	cout << "int\t" << TestFunc<int>(3) << endl ;
	cout << "double\t" << TestFunc<double>(3.3) << endl ;
	cout << "char\t" << TestFunc<char>('A') << endl ;
	cout << "char*\t" << TestFunc<char*>("TestString") << endl ;

	return 0 ;
}
