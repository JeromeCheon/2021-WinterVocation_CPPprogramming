#include <iostream>
#include <vector>
using namespace std ;

int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i){
        cout << v[i] << " " ;
    }
    cout << typeid(vector<int>::size_type).name() << endl ;
    cout << endl ;

    cout << v.size() << endl ;
    cout << v.capacity() << endl ; // 유일하게 vector만이 가지는 멤버 함수 .
    cout << v.max_size() << endl ;


    return 0 ;
}
/* 참조 (레퍼런스)
참조는 값을 복사하지 않고 같은 메모리 공간의 이름(참조) 이다.
    한편, vector 는 크기를 반환하는 세 맴버 함수 size(), capacity(), max_size()를 갖는다.
    size()는 저장 원소의 개수, capacity는 실제 할당된 메모리 공간의 크기, max_size()는 컨테이너가 담을 수 있는 최대 원소의 개수
    벡터는 배열 기반 컨테이너이기 때문에 원소를 추가하면 메모리를 재할당해야 하는 문제가 있다.
    원소가 추가될 때마다 메모리를 재할당하고 이전 원소를 모두 복사해야 한다면 너무나 비효율적. 이 때의 성능 문제를 보완하고자 만들어진 개념이 capacity
*/
