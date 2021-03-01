#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct LessFunctor{
    bool operator()(int left, int right) const{ // 1. 함수 객체
        return left < right ;
    }
};

bool LessFun(int left, int right){ // 2. 함수 조건자
    return left < right ;
}
int main(){
    bool (*LessPtr)(int, int) = LessFun ;// 3. 함수 포인터 조건자
    LessFunctor lessfunctor ;

    // all return bool types
    cout << lessfunctor(10, 20) << endl ;
    cout << LessFun(10, 20) << endl ;
    cout << LessPtr(10, 20) << endl ;

    return 0 ;
}
