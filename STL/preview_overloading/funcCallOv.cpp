#include <iostream>

using namespace std ;
// 함추 호출 연산자 오버로딩(() 연산자) => 객체를 함수처럼 동작하게 하는 연산자.
// C++에서 Print(10)이라는 함수 호출 문장은 다음 세가지로 해석 가능
/*
    1. 함수 호출: Print가 함수 이름
    2. 함수 포인터: Print가 함수 포인터
    3. 함수 객체: Print가 함수 객체
*/
struct FuncObject{ // c++에서의 struct는 class와 같아. 차이점은 struct는 기본 접근제어자가 public이라는 것.
public:
    void operator()(int arg) const{
        cout << "정수: "<< arg << endl ;
    }
};

void Print1(int arg){
    cout << "정수 : " << arg << endl ;
}

int main(){
    void (*Print2)(int) = Print1 ;
    FuncObject Print3 ;
    Print1(10) ; // 첫째, '함수'를 사용한 정수 출력
    Print2(10) ; // 둘째, '함수포인터'를 사용한 정수 출력
    Print3(10) ; // 셋째, '함수 객체'를 사용한 정수출력
    FuncObject()(20) ; // 임시 객체로 호출 (암시적)
    FuncObject().operator()(30) ; // 임시 객체로 호출 (명시적)
    // 임시 객체는 그 문장에서 생성되고 벗어나면 소멸됨. 그 문장에서만 임시로 필요한 객체에 사용
    return 0 ;
}
