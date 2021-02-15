#include <iostream>
using namespace std ;
// 정적 함수 포인터는 함수 시그니처만 알면 쉽게 선언 할 수 있다.
void Print(int n){
    cout << "Global : " << n << endl ;
}

namespace A{
    void Print(int n){
        cout << "namespace A global func: " << n << endl ;
    }
}

class Point{
public:
    static void Print(int n){
        cout << "Member function : " << n << endl ;
    }
};
int main(){
    void (*fp)(int) ;

    Print(10) ;
    A::Print(10) ;
    Point::Print(10) ;
    fp = Print ;
    fp(10) ;
    fp = A::Print ;
    fp(10) ;
    fp = Point::Print ;
    fp(10) ;

    return 0 ;

}
