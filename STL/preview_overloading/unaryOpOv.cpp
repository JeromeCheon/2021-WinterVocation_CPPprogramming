#include <iostream>

using namespace std ;

class Point{
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
    void Print() const {cout << x << ", " << y << endl ;}
    const Point& operator++ (){
        // prefix ++ operator
        ++x, ++y ;
        return *this ;
    }
    const Point operator++(int){
        // postfix ++ operator
        Point pt(x, y) ;
        ++x, ++y ;
        return pt ;
        // 이렇게도 사용가능함
        /* Point tmp = *this ;
        ++*this ;
        return tmp ; */
    }

    const Point& operator-- (){
        --x, --y ;
        return *this ;
    }
    const Point operator--(int){
        Point tmp = *this;
        --(*this) ;
        return tmp ;
    }
private:
    int x, y ;
};

int main(){
    Point p1(2, 3), p2(2, 3) ;
    Point result ;
    result = --p1 ;
    p1.Print() ;
    result.Print() ;

    result = p2-- ;
    p2.Print() ;
    result.Print() ;
    return 0 ;

}
