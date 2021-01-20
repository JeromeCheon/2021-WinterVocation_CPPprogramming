#include <iostream>
#include <string>
#include <cstdio>

#define ADD(a, b)((a) + (b))
using namespace std ;
// namespace는 C++가 지원하는 각종 요소들을 한 범주로 묶어주기 위한 문법
int Add(int a, int b){
	return a+b ;
}

inline int AddNew(int a, int b){
	return a+ b ;
}

int main(void){
	int a, b ;
	scanf("%d%d", &a, &b) ;

	printf("ADD(): %d", ADD(a, b)) ;
	printf("Add(): %d", ADD(a, b)) ;
	printf("AddNew(): %d \n", AddNew(a, b)) ;

	return 0 ;
}
