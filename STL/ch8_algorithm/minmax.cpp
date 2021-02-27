#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

class Point{
    int x, y ;
public:
    explicit Point(int _x = 0, int _y = 0): x(_x), y(_y){ }
    int getX() const {return x ;}
    int getY() const {return y ;}
    void Print() const { cout << "(" << x << ", " << y << ")" << endl ; }
};

bool xcompare(const Point& left, const Point& right){
    return left.getX() < right.getX() ;
}

bool ycompare(const Point& left, const Point& right){
    return left.getY() < right.getY() ;
}

int main(){
    int a= 10, b = 20 ;
    int r ;
    r = max(a, b) ;
    cout << "max: " << r << endl ;
    r = min(a, b) ;
    cout << "min: " << r << endl ;

    Point pt1(5, 8), pt2(3, 9) ;
    Point pt3 ;
    pt3 = max(pt1, pt2, xcompare) ;
    cout << "x max: " ; pt3.Print() ;
    pt3 = max(pt1, pt2, ycompare) ;
    cout << "y max: " ; pt3.Print() ;

    return 0 ;

}
