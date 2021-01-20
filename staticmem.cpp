#include <iostream>

using namespace std ;

class testclass{
public:
	testclass(int param) : data(param) { count++ ; }
	int getter(void) { return data ;}
	void resetcount() {count = 0 ;}

	// 정적 메서드 선언 및 정의
	static int getcount(){
		return count ;
	}
private:
	int data ;
	// 정적 멤버 변수 선언 (정의는 아님)
	static int count ;
};

int testclass::count = 0 ;
int main(void){
	testclass a(5), b(10) ;

	// 정적 멤버에 접근
	cout << a.getcount() << endl ;
	b.resetcount() ;

	// 정적 멤버에 접근, 인스턴스 없이도 접근 가능
	cout << testclass::getcount() << endl ;

	return 0 ;
}
