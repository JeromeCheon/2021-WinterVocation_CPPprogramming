#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    std::vector<int> v;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;
    /* basical usage of binary_search
    if(binary_search(v.begin(), v.end(), 20))
        cout << "20 원소가 존재합니다. " <<endl ;
    else
        cout << " not exist" << endl ;
    */
    cout << "[v 원본]: " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<" " ;
    cout << endl ;

    // basic sorting criteria -> less
    sort(v.begin(), v.end()) ;
    cout << "[v: less sort]: " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<" " ;
    cout << endl ;

    // 비교 조건자 less 지정 (일반 버전 binary_search() 가능 )
    cout << "비교 less 찾기: " << binary_search(v.begin(), v.end(), 20, less<int>()) << endl ;

    // sorting criteria -> greater
    sort(v.begin(), v.end(), greater<int>()) ;
    cout << "[v: greater sort]: " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<" " ;
    cout << endl ;

    // 비교 조건자 less 지정 (일반 버전 binary_search() 가능 )
    cout << "비교 greater 찾기: " << binary_search(v.begin(), v.end(), 20, greater<int>()) << endl ;

    return 0 ;
}
