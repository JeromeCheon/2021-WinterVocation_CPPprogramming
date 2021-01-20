#include <iostream>

using namespace std ;

class test{
private:
	int data ;

public:
	test(int param) : data(param) {} ;
	~test() {}

	// 상수형 메서드로 선언 및 정의 했다. 
	int getter() const{
		// 멤버 변수의 값을 읽을 수는 있지만 쓸 수는 없다. 즉 getter를 사용하거나 직접 정의할 수는 없다는 것.
		return data ;
	}

	int setter(int param) { data = param ; }
};

int main(void){
	test a(10) ;
	cout << a.getter() << endl ;

	return 0 ;
}
