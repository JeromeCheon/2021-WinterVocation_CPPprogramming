#include <iostream>
using namespace std ;

void Print(int n){
    cout <<"Interger: "<<  n << endl ;
}

int main(){
    // void Print(int n)의 함수 포인터 선언
    void (*fp)(int) ;
    // 함수의 이름은 함수의 시작 주소
    fp = Print ;
    Print(10) ;
    fp(10) ;
    (*fp)(10) ;
    cout << endl ;
    cout << &Print << endl ;
    cout << fp << endl ;
    cout << *fp << endl ;

    return 0;
    /*
    int n = 30 ;
    int *pn = &n ;  // 자 이렇게 참조변수 기호를 두고 포인터를 쓰면 값을 변경하기 위해서는 포인터를 불러야 해. 그냥 pn하면 이 포인터의 주소를 건드는 것.

    *pn = 40 ;
    cout << *pn <<"\t" << n << endl ;
    return 0;*/
}
