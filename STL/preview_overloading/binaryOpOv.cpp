#include <iostream>

using namespace std ;
/*
    연산자 오버로딩에는 두가지가 있다.
    1. 지금까지 학습한 멤버함수를 이용한 연산자 오버로딩 (일반적으로 사용.)
    2. 전역함수를 이용한 연산자 오버로딩
    1번이 안되면 2번을 이용해서 연산자 오버로딩을 해야 하는데 그런 경우는, 두가지 항이 있으면 어느 한쪽 항이 연산자 오버로딩 객체가 아닐때.
*/
class Point{
private: // default 가 private이기 때문에 생략 가능
    int x, y ;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y){}
    // void operator+=(const Point &rhs){
    //     cout << "op +=" <<endl ;
    // }
    // bool operator==(const Point &rhs) const {
    //     return (x==rhs.x && y == rhs.y) ? true : false ;
    // }
    void Print() const {
        cout << x << ", " << y << endl ;
    }
    int getX() const { return x ;}
    int getY() const { return y ;}

    // const Point operator-(const Point &rhs) const
    //     {return Point(x-rhs.x, y-rhs.y) ;}

};
// Operator overloading using a global function
const Point operator-(const Point &arg1, const Point &arg2){
    return Point(arg1.getX() - arg2.getX(), arg1.getY() - arg2.getY()) ;
}

int main(){
    Point p1(2,3), p2(5,5) ;
    Point p3 ;
    p3 = p1 - p2 ;
    p3.Print() ;
    return 0 ;
}
