#include <iostream>
using namespace std ;

class Point{
    int x;
    int y ;
public:
    explicit Point(int _x = 0, int _y = 0): x(_x), y(_y) {}
    void Print() const {cout << x <<", " << y << endl ;}
    void PrintInt(int n){ cout << "Test integer :" << n << endl ;}

};

int main(){
    Point pt(2, 3) ;
    Point *p = &pt ;
    void (Point::*fp1)() const;
    fp1 = &Point::Print ;
    void (Point::*fp2)(int) ;
    fp2 = &Point::PrintInt ;

    pt.Print() ;
    pt.PrintInt(10) ;

    (pt.*fp1)() ;
    (pt.*fp2)(10) ;

    (p->*fp1)() ;
    (p->*fp2)(10) ;

    return 0 ;
}
