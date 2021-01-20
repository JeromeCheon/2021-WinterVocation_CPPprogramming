/* 깊은 복사와 얕은 복사.
   깊은 복사 : 복사에 의해 실제로 두 개의 값이 생성되는 것.
   얕은 복사는 대상이 되는 값은 여전히 하나뿐인데 접근 포인터만 둘로 늘어나는 것.
   eg) 아가씨 한명 두고 두 남자가 결투를 벌이는 모습.
   int lady ;
   int *he1 *he2 ;
   he1 = &lady ; he2 = &lady ; // 이런식으로. 
   */
#include <iostream>

using namespace std ;
/*
class test{
public:
	test(int param){
		data = new int ; // int 형 인스턴스 생성
		*data = param ;
	}
	
	int getter() const {
		if(data != NULL){
			return *data ;
		}
		return 0 ;
	}
private:
	int *data = nullptr ;
};

int main(){
	test a(10) ;
	test b(a) ; // 복사 생성자를 따로 정의 안해줬으므로 컴파일러가 자동으로 만든 복사생성자 이용.
	// 근데 정상 작동 하는 것 처럼 보이는 것은 메모리 해제를 안했기 때문.
	// 만약 제작자가 메모리 누수를 의식해서 소멸자에 delete ptr 를 하면 얕은 복사로 인한 심각한 오류 발생! 
	// 따라서 깊은 복사로 바꿔줘야 하고 그 코드는 다음과 같이 될 것이다.
	cout << a.getter() << endl ;
	cout << b.getter() << endl ;
}*/
#include <iostream>

using namespace std ;

class test{
public:
	test(int param){
		data = new int ;
		*data = param ;
	}
	// declare and define a copy constructor
	test(const test &rhs){
		cout << "copy constructor" << endl ;

		// allign memory
		data = new int ;
		// copy the value toword the location where the pointer indicates
		*data = *rhs.data ;
	}
	// when destruct the instance, then deallocate the momory
	~test(){ delete data ; }

	int getter() const{
		if(data != NULL)
			return *data ;
		return 0 ;
	}
private:
	// pointer member data
	int *data = nullptr ;
};

int main(){
	test a(10) ;
	test b(a) ;
	cout << a.getter() << endl ;
	cout << b.getter() << endl ;

	return  0;
}
