#include <iostream>
#include <cstdio>
#include <string>

// c++과 C의 중요한 차이점 중 하나는 바로 '다중 정의'. 이름이 같은 함수가 동시에 여러 개 존재할 수 있다. 
// 또 하나의 차이점으로는 네임스페이스. 범위 지정 방법을 통해 더 체계적으로 코드를 관리할 수 있게 해줌

using namespace std ;

int main(void){
	// 인스턴스만 동적으로 생성하는 경우
	int *pdata = new int ;
	
	int *chck(pdata) ;

	// 초깃값을 기술하는 경우. 한편, 이 초깃값은 함수도 가질 수 있음 int add(int a=10, int b=20){} 이렇게. 
	int *pnewData = new int(10) ;
	*pdata = 5 ;
	
	cout << "pdata: " << *pdata << "\n copied chck : " << *chck << endl ;
	cout << "pnewData : " << *pnewData << endl ;
	
	delete pdata ;
	//delete chck ;
	delete pnewData ;
}
