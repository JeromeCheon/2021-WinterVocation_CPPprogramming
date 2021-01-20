#include <iostream>
#include "MyString.h"
#include <string>
#include <cstring>

using namespace std ;

CMyString::CMyString() : m_pszData(NULL), m_nLength(0){}
CMyString::CMyString(const char* str){
	this->setString((str)) ;
	m_nLength = 0 ;
}
// copy constructor
CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0){
	this->setString(rhs.getString()) ;
}
// copy cons for operator
CMyString& CMyString::operator=(const CMyString &rhs){
	if (this != &rhs) {
		this->setString(rhs.getString()) ;
	}
	return *this ;
}
// CMyString::operator char*(void){return const_cast<char*>(getString()); }
CMyString::operator char*() const {return m_pszData ;}

CMyString::~CMyString(){
	Release() ;
}

int CMyString::setString(const char* pszParam){
	// 새로운 문자열 할당에 앞서 기존 정보를 해제한다.
	Release() ;

	if(pszParam == NULL)
		return 0 ;
	/*string* temp = new string(pszParam) ;
	//temp = pszParam ;
	if(temp->length() == 0){
		cout << "Input String Length is 0 " << endl ;
		return 0 ;
	}
	m_nLength = temp->length() ;
	strcpy(m_pszData, pszParam) ;
	delete temp ;
	return 0 ;*/

	// 모범 답안
	// 길이가 0인 문자열도 초기화로 인식하고 처리
	int nLength = strlen(pszParam) ;
	if(nLength == 0)
		return 0 ;

	// 문자열의 끝인 NULL을 고려해 메모리를 할당함.
	m_pszData = new char[nLength + 1] ;
	strcpy(m_pszData, pszParam) ;
	//strcpy(m_pszData, sizeof(char)* (nLength + 1), pszParam) ;
	m_nLength = nLength ;

	//문자열 길이 반환
	return nLength ;
}
const char* CMyString::getString() const{
	return m_pszData ;
}

void CMyString::Release(){
	// 이 함수가 여러번 호출 될 경우를 고려해 주요 멤버를 초기화 함
	if(m_pszData != NULL)
		delete[] m_pszData ;
	m_pszData = NULL ;
	m_nLength = 0 ;
}
