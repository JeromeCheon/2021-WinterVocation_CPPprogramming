#include <iostream>
#include <cstdio>

using namespace std ;

/* ver.1
class testclass{
public:
		// 디폴트 생성자는 없다.
	// 매개 변수가 int 하나인 생성자 함수 선언 및 정의
	testclass(int nparam) : data(nparam) {} ;

	// 매개변수가 int 자료형 두개인 생성자 함수 다중 정의
	testclass(int x, int y) : data(x + y) {} ;

	int getter(void) { return data ; }

private:
	int data ;
};

int main(void){
	testclass a(10) ;
	testclass b(3, 4) ;

	cout << a.getter() << endl ;
	cout << b.getter() << endl ;

	return 0 ;
}
*/

class testclass{
public:
	testclass(int x){
		cout << "testclass(int)" << endl ;

		// test if x > 100
		if(x > 100)
			x = 100 ;
		m_x = 100 ;
	}

	testclass(int x, int y)
		// x 값을 검사하는 코드는 있으므로 이렇게 호출하여 코드 중복 방지
		: testclass(x)
	{
		cout << "testclass(int, int)" << endl ;

		if(y> 200)
			y = 200 ;
		m_y = 200 ;
	}

	void Print(){
		cout << "X: " << m_x << endl ;
		cout << "Y: " << m_y << endl ;
	}

private:
	int m_x = 0;
	int m_y = 0 ;
};

int main(void){
	testclass a(10) ;
	a.Print() ;

	testclass b(100, 20) ;
	b.Print() ;

	return 0 ;
}
