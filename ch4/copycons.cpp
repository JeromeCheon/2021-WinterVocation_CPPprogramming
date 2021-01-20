/**
  copy constructor.
  복사생성자라고 하며, 객체의 복사본을 생성할 때 호출되는 생성자이다. 클래스를 작성할 때 이 복사 생성자를 생략하면 디폴트 생성자처럼 컴파일러가 알아서 만들어 넣어준다. 
  문법은 : classname(const classname &rhs) ;

  */
#include <iostream>

using namespace std ;

class test{
public:
	test(){
		cout << "default constructor" << endl ;
	}

	test(const test &rhs) : data(rhs.data) {
		// this->data = rhs.data ; 이렇게 해도 되고,  생성자 초기화 목록 사용해도 되고! 
		cout << "copy constructor" << endl; 
	}
	~test(){
		cout << "destructor" << endl ;
	}
	int getter() const { return data ; }
	void setter(int param) { data = param ; }

private:
	int data ;
};

int main(){
	test a ;
	a.setter(10) ;

	// call copy constructor
	test b(a) ;
	cout << b.getter() << endl ;

	return 0 ;
}
