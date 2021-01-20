#include <iostream>
#include "MyString.h"
#include "MyString.cpp"
#include <cstdio>

using namespace std ;

void Testfunc(const CMyString &strParam){
	cout << strParam << endl ;
}

int main(void){
	CMyString strData("Hello") ;
	::Testfunc(strData) ;
	::Testfunc(CMyString("World")) ;

	return 0 ;
}
