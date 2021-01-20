#include <iostream>
#include <string>
#include <cstdio>

using namespace std ;

int main(){
	int age ;
	cout << " 나이를 입력하세요. " << endl ;
	cin >> age ;

	char job[32] ;
	cout << " enter your job. " << endl ;
	cin >> job ;
	
	string name ;
	cout << "Enter your name. " << endl ;
	cin >> name ;

	cout << " Your name is " << name
		<< "and the age is " << age << " , the job is " << job
		<< endl ;
	return 0 ;
}

