#pragma once

#include <iostream>
#include <string>
#include <cstring>
//#include "MyString.cpp"

using namespace std ;

class CMyString{

public:
	CMyString() ;	// constructor
	~CMyString() ;	// destructor
	explicit CMyString(const char* str) ;
	// copy constructor
	CMyString(const CMyString &rhs) ;

	// copy constructor for operator
	CMyString& operator=(const CMyString &rhs) ;

	operator char*() const;	// 이렇게 const를 붙여준다!
	int setString(const char* pszParam) ;
	const char* getString() const;
	void Release() ;

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData ;//= NULL;

	// mutable로 선언한 멤버 변수의 값은 상수형 메서드에서도 쓰기가 허용됨.

	// 저장된 문자열 길이
	int m_nLength ;
};
