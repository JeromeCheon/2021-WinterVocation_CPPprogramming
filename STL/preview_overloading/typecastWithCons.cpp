#include <iostream>

using namespace std ;

class A{

};
class B{
public:
    // B() {cout << "B constructor" << endl ;}
    // B(A& a){ cout <<" B(A a) constructor" << endl ;}
    // B(int n) {cout << "B(int) constructor" << endl ;}
    // B(double d) { cout << "B(double) constructor" << endl ;}
    operator A(){
        cout << "op A() call" << endl ;
        return A() ;
    }
    operator int(){
        cout << "op int() call" << endl ;
        return 10 ;
    }
    operator double(){
        cout << "op double() call" << endl ;
        return 20.2 ;
    }
};

int main(){
    A a ;
    int n ;
    double d ;
    B b ;
    a = b ;
    n = b ;
    d = b ;
    return 0 ;
}
//
// class Point{
// private:
//     int x, y ;
// public:
//     // Point(){}
//     explicit Point(int _x=0, int _y=0) : x(_x), y(_y){}
//     void Print() const { cout << x << ", " << y << endl ;}
// };
//
// int main(){
//     Point pt;
//     pt.Print() ;
//     //pt = 10 ; // error! 암시적 생성자 호출이 불가능!
//
//     pt = Point(10) ;
//     pt.Print() ;
//
//     return 0 ;
// }
