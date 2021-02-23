/*
대표적인 함수 어뎁터 not2. 조건자 함수 객체를 반대 의미의 조건자 함수 객체로 변경하는 어댑터.
not1은 단항 조건자에, not2는 이항 조건자에 사용

*/
#include <iostream>
#include <functional>
using namespace std ;

int main(){
    cout << less<int>()(10, 20) << endl ;
    cout << less<int>()(20, 10) << endl ;
    cout << less<int>()(20, 20) << endl ;
    cout << "==============" << endl ;
    cout << not2(less<int>())(10, 20) << endl ; // 반대의미의 객체를 반환. 
    // 임시 객체 less에 not2 어댑터 적용
    cout << not2(less<int>())(20, 10) << endl ;
    cout << not2(less<int>())(20, 20) << endl ;
    cout << endl ;
    less<int> l ;
    cout << l(10, 20) << endl ;
    cout << l(20, 10) << endl ;
    cout << l(20, 20) << endl ;
    cout << "==============" << endl ;

    cout << not2(l)(10, 20) << endl ;
    cout << not2(l)(20, 10) << endl ;
    cout << not2(l)(20, 20) << endl ;
}
