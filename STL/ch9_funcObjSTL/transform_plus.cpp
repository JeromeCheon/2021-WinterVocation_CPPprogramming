#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

template<typename T>
class Plus : public binary_function<T, T, T>{

public:
    // 이 typedef는 사용자 함수 객체도 어댑터 적용이 가능하도록 하는 것. 이게 없으면 binder1st 를 Plus<int>()와 묶었을 때 에러나.
    // 이렇게 할 수 있는데, 좀 더 쉽고 편하게 할 수 있는 건 기본 클래스인 unary_function과 binary_function을 상속받아 구현하는 것.
    // typedef T first_argument_type ;
    // typedef T second_argument_type ;
    // typedef T result_type ;
    T operator() (const T& left, const T& right) const {
        return left + right ;
    }

};

int main(){
    vector<int> v1 ;
    v1.push_back(10) ;
    v1.push_back(20) ;
    v1.push_back(30) ;

    vector<int> v2 ;
    v2.push_back(1) ;
    v2.push_back(2) ;
    v2.push_back(3) ;

    vector<int> v3(3) ;

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus<int>()) ;
    // STL 조건자 plus<int>()
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>()) ;

    // adapter 사용!
    // transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> >(plus<int>(), 100 )) ;
    // 사용자 정의 Plus 사용
    transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> >(Plus<int>(), 100 )) ;
    cout << "v1 : " ;
    for(vector<int>::size_type i = 0 ; i < v1.size() ; i++)
        cout << v1[i] << endl ;
    cout <<endl ;

    cout << "v2 : " ;
    for(vector<int>::size_type i = 0 ; i < v2.size() ; i++)
        cout << v2[i] << endl ;
    cout <<endl ;

    cout << "v3 : " ;
    for(vector<int>::size_type i = 0 ; i < v3.size() ; i++)
        cout << v3[i] << endl ;
    cout <<endl ;

    return 0 ;
}
