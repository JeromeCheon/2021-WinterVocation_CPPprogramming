#include <iostream>

using namespace std ;

class CRefTest{
public:
	// 참조형 멤버는 반드시 생성자 초기화 목록을 이용해 초기화 한다. 
	CRefTest(int &rParam) : data(rParam){} ;
	int GetData(void){
		return data ;
	}

private:
	// 참조형 멤버는 객체가 생성될 때 반드시 초기화 해야 한다. 
	int &data ;
};

// User code 
int main(){
	int a = 10 ;
	CRefTest t(a) ;

	cout << t.GetData() << endl ;

	// 참조 원본인 a의 값이 수정되었다.,

	a= 20 ;
	cout << t.GetData() << endl ;

	return 0 ;
}
