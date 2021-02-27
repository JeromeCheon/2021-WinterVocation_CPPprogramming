#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

void Print(int n){
    // 모든 원소에 대해 Print(*p)를 적용한다.
    cout << n << " " ;
}
// 여기에 함수자를 더한 것
class PrintFunctor{
    char fmt ;
public:
    explicit PrintFunctor(char c = ' '): fmt(c){}
    void operator()(int n) const{
        cout << n << fmt ;
    }
};

int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    // for_each(v.begin(), v.begin()+2, Print) ;
    for_each(v.begin(), v.end(), PrintFunctor()) ;  // 함수자를 사용하여 다양한 출력 패턴을 적용해 볼 수 있다. 
    cout << endl ;
    // for_each(v.begin(), v.begin()+4, Print) ;
    for_each(v.begin(), v.end(), PrintFunctor(',')) ;
    cout << endl ;
    // [v.begin(), v.end()) 구간의 원소 출력
    // for_each(v.begin(), v.end(), Print) ;
    for_each(v.begin(), v.end(), PrintFunctor('\n')) ;
    cout << endl ;

    return 0 ;
}
