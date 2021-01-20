#include <iostream>
using namespace std ;

class test{
public:
	test(int param) : data(param) {
		cout << "constructor" << endl ;
	}
 	// 이 코드는 잘 짜여진 코드가 아냐. 왜? 생성자를 두 번 사용해야 하고 이는 장기적인 관점으로 매우 안좋아. 
	// 이럴 때, 복사 생성자의 생성을 원천 차단 할 수도 있다. 코드는
	/*
	test(const test &rhs) = delete ; // 이렇게 delete로 막아버리는 것. 
	더 우아한 방법이 있는데 바로 참조자를 쓰는것
	void testfunc(test &param)으로 하면 객체가 생성이 되지 않는다!
	*/
	test(const test &rhs) {
		this->data = rhs.data ;
		cout << "copy constructor" << endl ;
	}
	int getter(void) { return data ; }
	void setter(int param) { data = param ; } 
private:
	int data = 0 ;
};

// 매개변수가 test 클래스 형식이므로 복사 생성자가 호출됨
void testfunc(test &param){
	cout << "testfunc" << endl ;

	// 피호출자 함수에서 매개변수 인스턴스 값을 변경한다.
	param.setter(20) ;
}

int main(void){
	cout << "**********Begin********" << endl ;
	test a(10) ;
	testfunc(a) ;

	cout << "a: " << a.getter() << endl ;
	cout << "End +++++++++++++++++++" << endl ;

	return 0 ;
}
