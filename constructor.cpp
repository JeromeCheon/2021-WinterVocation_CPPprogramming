#include <iostream>

using namespace std ;
class CTest{
	int data;
public:
	// 생성자의 매개변수로 전달된 값으로 멤버 변수를 초기화 한다.
	CTest(int nParam): data(nParam){
		cout << "Ctest::CTest()" << endl ;
	}
	~CTest(){
		cout << "~CTest::CTest() " << data << endl ;
	}
};

int main(){
	cout << "Begin" << endl ;
	CTest a(1) ;
	cout << "Before b" << endl ;
	CTest b(2) ;
	cout << "end" << endl ;

	return 0 ;
}
