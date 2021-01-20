#include <iostream>

using namespace std ;
/* 덩치 큰 자료형은 값 대신 주소를 전달하는 것이 효율적이다. */
void TestFunc(int &param) ;

// 한편 r-value 참조라는 것이 있는데 사용법은 && 두번쓰면 되고, 값을 변경할 수 있는데, 
// 쉽게  말해 3+4+5 연산에서 3+4 연산의 결과를 '임시 결과'라고 하는 것과 같다. 

int main(){
	int data = 10 ;
	int &ref = data ;

	ref = 20 ;

	cout << data << endl ;

	int *pdata = &data ;
	*pdata = 30 ;
	cout << data << endl ;
	
	int arr[5] = {10, 20, 30, 40, 50} ;
	for(auto n : arr)
		cout << n << " " ;
	cout << endl ;

	for(auto &n : arr)
		cout << n << " " ;
	cout << endl ;

	TestFunc(data) ;

	cout << data << endl ;
	return 0 ;
}

void TestFunc(int& param){
	//  피호출자 함수에서 원본의 값을 변경했다. 
	param = 100 ;
}

