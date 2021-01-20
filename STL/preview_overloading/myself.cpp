#include <iostream>

using namespace std ;

class Point{
    int x, y ;
public:
    Point(int _x, int _y) : x(_x), y(_y){
        cout << "called constructor" << endl ;
    }
    void Print() const {
        cout << x << ", " << y << endl ;
    }
    ~Point(){
        cout << "called destructor" << endl ;
    }

};

class Pointptr{
    Point *ptr ;
public:
    Pointptr(Point *p) : ptr(p){}
    ~Pointptr(){ delete ptr ; }

    Point* operator->() const {
        return ptr ;
    }
};

int main(){
    Pointptr p1 = new Point(3, 3) ;
    Pointptr p2 = new Point(1, 2) ;

    // p1->Print() ;
    // p2->Print() ;
    p1.operator->()->Print() ;
    p2.operator->()->Print() ;

    return 0 ;
}
