#include <iostream>
// 연산자 오버로딩을 사용하면 컴파일러 내부에 정의되지 않은 타입의 연산이 가능하여 코드의 직관성과
// 가독성을 좋게 할 수 있음
// 연산자 오버로딩은 컴파일러와 약속된 함수를 이용해 사용자 정의 타입에 연산이 가능하도록 제공하는 것.
/*  알아둬야 할 배경지식!!
    const 멤버 함수와 비 const 멤버 함수
    => const 멤버함수는 멤버 함수 내에서 객체의 멤버 변수를 변경하지 않는다는 것을 보장하는 함수.
    따라서 const 객체는 const 멤버 함수만 호출할 수 있음. const 멤버 함수에서 멤버 변수를 변경하면 컴파일러 에러!
    자신의 멤버를 변경하지 않는 멤버 함수는 모두 const 멤버 함수여야만 함.

*/
using namespace std ;
// user defined class
class Point{
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const {
        cout << x << ", " << y << endl ;
    }
    // Point operator+(const Point &rhs) { // 이렇게 해도 되고, 정답은
    const Point operator+(const Point &rhs) const { // this is the answer
        Point pt ;
        pt.x = this->x + rhs.x ;
        pt.y = this->y + rhs.y ;

        return pt ;
    }

private:
    int x, y ;
} ;

int main(){
    Point  p1(2, 3), p2(5, 5) ;
    Point p3 ;
    p3 = p1 + p2 ; // => p1.operator+(p2) ; 와 같음
    p3.Print() ;
    p3 = p1.operator+(p2) ;
    p3.Print() ;
    // p1 * p2 ;
    // p1 = p2 ;
    // p1 == p2 ;
    // p1 += p2 ;

    return 0 ;
}
