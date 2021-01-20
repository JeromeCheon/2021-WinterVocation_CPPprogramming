#include <iostream>

using namespace std ;

class test{
public:
	test(int param, char* str) : data(param), name(str){
		cout << "test(int)" << name << endl ;
	}

	~test(){
		cout << "~test()" << name << endl ;
	}
	test(const test &rhs) : data(rhs.data), name(rhs.name){
		cout << "copy constructor" << name << endl ;
	}
	test& operator=(const test &rhs){
		cout << "operator= " << endl ;
		// 값은 변경하지만 이름은 그대로 둔다
		data = rhs.data ;

		return *this ;
	}
	int getter(){
		return data ;
	}
	void setter(int param){
		data = param ;
	}
private:
	int data = 0;

	// 변수 이름을 저장하기 위한 멤버
	char *name = nullptr ;
};

// test 의 객체를 반환하는 함수
test testfunc(int param){
	//test 클래스 인스턴스인 a는 지역변수 이다.
	//따라서 함수가 반환되면 소멸한다.
	test a(param, "a") ;
	return a ;
}

int main(){
	test b(5, "b") ;
	cout << "*******Before******" << endl ;

	// 함수가 반환되면서 임시객체가 생성되었다가 대입 연산 후 즉시 소멸한다.
	b = testfunc(10) ;
	cout << "*******After*******" << endl ;
	cout << b.getter() << endl ;

	return 0 ;
}
