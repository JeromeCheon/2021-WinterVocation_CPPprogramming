#include <iostream>

using namespace std ;

class test{
public:
	// 매개변수가 하나뿐인 생성자는 형변환이 가능하다.
	// 근데 explicit 예약어를 쓰면 묵시적으로 형변환이 불가하도록 차단한다. 
	// 클래스가 변환 생성자를 제공하면 두 형식 사이에 호환성이 생김
	// 가령 CTest 라는 클래스에서 int 자료형에 대한 변환 생성자를 제공했다면 int 자료형이 CTest 형식으로 변할 수 있다. 
	// 이는 형변환 연산자를 만들어 놓음으로써 완전해진다. 

	explicit test(int param) : data(param){
		cout << "constructor" << endl ;
	}
	
	operator int(void) { return data ; }

	//copy constructor
	test(const test &rhs){
		this->data = rhs.data ;
		cout << "copy constructor" << endl ;
	}
	~test(){ cout << "destructor" << endl ; }
	int getter() const {return data ; }
	void setter(int param) { data = param ; }
private:
	int data ;
};
// user code
// 매개변수가 클래스 형식이며 변환 생성이 가능하다
void func(const test &param){
	cout << "test function" << endl ;
}


int main(void) {
	// func(5) ;
	test a(10) ;
	cout << a.getter() << endl ;

	// test형식에서 int type convertable
	cout << a << endl ;
	cout << (int)a << endl ; // 이는 c형식 강제 형변환
	// static_cast는 제약이 있지만 실수를 방지해주는 c++ 전용 형변환이고 이러한 형변환 연산자들로는,
	// const_cast | static_cast | dynamic_cast | reinterpret_cast 가 있다. 
	cout << static_cast<int>(a) << endl ;

	return 0 ;
}
