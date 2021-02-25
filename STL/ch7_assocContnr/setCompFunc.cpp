#include <iostream>
#include <set>

using namespace std ;

int main(){
    set<int, less<int> > s_less ;
    set<int, greater<int> > s_greater ;

    s_less.insert(50) ;
    s_less.insert(80) ;
    s_less.insert(40) ;

    s_greater.insert(50) ;
    s_greater.insert(80) ;
    s_greater.insert(40) ;

    set<int, less<int> >::key_compare l_cmp = s_less.key_comp() ;
    cout << l_cmp(10, 20) << endl ;

    set<int, greater<int> >::key_compare g_cmp = s_greater.key_comp() ;
    cout << g_cmp(10, 20) ;

    cout << "key_compare type: " << typeid(s_less.key_comp()).name() << endl ;
    cout << "key_compare type: " << typeid(s_greater.key_comp()).name() << endl ;
    cout << "value_compare type: " << typeid(s_less.value_comp()).name() << endl ;
    cout << "value_compare type: " << typeid(s_greater.value_comp()).name() << endl ;

    return 0 ;
}
/*
연관 컨테이너는 모두 같은 인터페이스의 멤버 함수를 제공함. 이 연관 컨테이너의 핵심은 찾기 관련 멤버 함수이다.
찾기 관련 멤버함수는 정렬 기준으로 트리의 루트 노드부터 자식 노드로 검색을 진행하므로 로그 시간 복잡도에 실행되며, count(), find(), lower_bound, upper_bound, equal_range 멤버 함수.

*/
