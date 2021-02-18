#include <iostream>
using namespace std ;
/*
    템플릿 함수를 사용하면 컴파일러는 클라이언트의 함수 호출 인자 타입을 보고 템플릿 함수의 매개변수 타입을 정하여
    실제 함수인 템플릿 인스턴스 함수를 생성함

    서버 함수는 일반화된 기능만을 제공하고 클라이언트가 함수의 매개변수 타입을 결정함
    Usage:
    Template<typename T> ~~ void Print(T a, T b) 이런식으로 사용
    이렇게 되면 예제에서는 Print<int>(), Print<double>(), Print<const char*>()를 생성함.      -> Print<T>()

    또 템플릿도 함수처럼 여러 매개변수를 가질 수 있음. 두개의 매개변수를 가질려면
    Template<typename T1, typename T2>          한편, c++ 표준화 이전 부터 사용되던 template<class T>도 사용가능
*/
template<typename T>
void Print(T a, T b){
    cout << a << ", " << b << endl ;
}

int main(){
    Print(10, 20) ;
    Print(.23, .45) ;
    Print("Hello", " Universe") ;

    return 0 ;
}
