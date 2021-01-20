#include <iostream>

using namespace std ;

class CTest{
	// 한편, 기본 접근 제어자는 private이다. 따라서 생성자를 오버라이드 할 때 public안에서 해야 한다. 
	public:
		// constructor
		CTest()
			: data1(10), data2(20)
		{
			// 인스턴스가 생성되면 멤버 데이터를 자동으로 초기화 한다.
			cout << "CTest() : 생성자 함수" << endl ;
		}

		// 멤버 데이터 선언
		int data1, data2 ;


		void PrintData(void){
			cout << data1 << endl ;
			cout << data2 << endl ;

		}
};

int main(void){
	cout << " main()  start! " << endl ;

	CTest t ;
	t.PrintData() ;

	cout << " main() end! " << endl ;

	return 0 ;
}
