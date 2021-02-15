#include <iostream>
/*
    c++에서 함수는 정적 함수와 멤버함수로 나눌 수 있다. 여기서 정적 함수로는 전역 함수, namespace 내의 전역함수, static 맴버함수\
    멤버함수는 다시 객체와 주소로 각각 호출 할 수 있으므로 함수 호출은 세가지가 있다.
    1. 정적 함수 호출(정적 함수)
    2. 객체로 맴버 함수 호출(멤버 함수)
    3. 객체의 주소로 멤버 함수 호출(멤버 함수)
*/
using namespace std ;

void Print(){
    cout << "Static function~ " << endl;
}

class Point{
public:
    void Print(){
        cout << "Member function~" << endl ;
    }
};

int main(){
    Point pt ;
    Point *p = &pt ;

    Print() ;       // 1. 정적 함수 호출
    pt.Print() ;    // 2. 객체로 멤버 함수 호출
    p->Print() ;    // 3. 주소로 멤버 함수 호출
    return 0 ;
}
