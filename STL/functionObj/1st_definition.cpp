#include <iostream>
using namespace std ;
/*
    함수 객체의 장점 : 함수처럼 동작하는 객체이므로 다른 멤버 변수와 멤버 함수를 가질 수 있고 일반 함수에서 하지 못하는 지원을 받을 수 있음
    또 함수 객체의 서명이 같더라도 객체 타입이 다르면 서로 전혀 다른 타입으로 인식함
    속도도 함수객체가 더 빨라 
*/

void Print(){
    cout << "Global function! " << endl ;
}

struct Functor{
    void operator()(){
        cout << "function object ! " << endl ;
    }
};

int main(){
    Functor functor ;
    Print() ;
    functor() ;

    return 0;
}
