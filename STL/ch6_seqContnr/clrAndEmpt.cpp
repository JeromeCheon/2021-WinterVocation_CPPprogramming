#include <iostream>
#include <vector>
using namespace std ;
// [] 연산자와 at() 멤버 함수 두 인터페이스의 기능은 같지만, [] 연산자는 범위 점검을 하지 않아 속도가 빠르고, at() 멤버함수는 범위 점검 -> 속도는 느리지만 안전. 
int main(){
    vector<int> v(5) ;
    v[0] = 10 ;
    v[1] = 20 ;
    v[2] = 30 ;
    v[3] = 40 ;
    v[4] = 50 ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i){
        cout << v[i] << endl ;
    }
    cout << endl ;
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl ;

    cout << v.front() << v.back() << endl ;
    v.clear() ;
    vector<int>().swap(v) ; // c++에서는 직접 capacity를 초기화 해줄 수는 없지만, 대신 swap 함수 제공으로 기본 생성자로 만든 컨테이너와 바꿀 수 있게 함
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl ;
    if(v.empty())
        cout << "v is empty! " << endl ;

    return 0 ;

}
