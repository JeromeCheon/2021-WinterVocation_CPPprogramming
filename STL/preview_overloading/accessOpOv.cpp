#include <iostream>

using namespace std ;

/*  메모리 접근, 클래스 멤버 접근 연산자 오버로딩(*, -> 연산자)
    이 연산자들은 스마트 포인터나 반복자 등의 특수한 객체에 사용됨. 반복자가 STL의 핵심 구성 요소이므로 *, -> 연산자 오버로딩이 아주 중요!
    스마트 포인터는 일반 포인터의 기능에 몇가지 유용한 기능들을 추가한 포인터 처럼 동작하는 객체.

*/

class Point {
    int x, y ;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y){

    }
    void Print(){
        cout << x << ", " << y << endl ;
    }
};
// smart pointer
class Pointptr{
    Point *ptr ;
public:
    Pointptr(Point *p): ptr(p){}
    ~Pointptr(){ // 이렇게 스마트 포인터를 만들어서 접근하면 소멸자가 자동으로 메모리를 해제하여 반환해줌. 누수 방지.
        delete ptr ;
    }
    Point* operator->() const {
        return ptr ;
    }
    Point& operator* () const{
        return *ptr ;
    }
};

int main(){

    /*  기존 일반 포인터 방식
    Point *p1 = new Point(2, 3) ;
    Point *p2 = new Point(5, 5) ;
    p1->Print() ;
    p2->Print() ;

    delete p1 ;
    delete p2 ;
    */
    Pointptr p1 = new Point(2, 3) ;
    Pointptr p2 = new Point(5,5) ;

    p1->Print() ;
    p2->Print() ;
    (*p2).Print() ;
    return 0 ;
}
