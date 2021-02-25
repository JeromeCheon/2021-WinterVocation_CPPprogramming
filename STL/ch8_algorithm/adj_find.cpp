#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
/*
int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(40) ;
    v.push_back(50) ;

    for(std::vector<int>::size_type i; i < v.size() ; i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
    vector<int>::iterator iter ;
    iter = adjacent_find(v.begin(), v.end()) ;  // 같아지는 첫 원소 반복자를 반환

    if(iter != v.end()) // 같은 원소가 없다면 구간의 끝 반복자 반환
        cout << *iter << endl ;
    for( ; iter != v.end() ; ++iter)
        cout << *iter << " " ;
    cout << endl ;

    return 0 ;
}
*/
int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    for(vector<int>::size_type i=0 ; i < v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl ;

    vector<int>::iterator iter ;
    vector<int>::iterator iter_b = v.begin() ;
    vector<int>::iterator iter_e = v.begin() +2 ;
    // [iter_b, iter_e)의 순차열은 10, 20 이므로 찾는 원소가 없어 iter는 구간의 끝인 iter_e이다.
    iter = adjacent_find(iter_b, iter_e) ;

    if(iter != iter_e)
        cout << *iter << endl ;
    cout << "======================" << endl ;
    if(iter != v.end())
        cout << *iter << endl ;
    iter_b = v.begin() ;
    iter_e = v.end() ;
    iter = adjacent_find(iter_b, iter_e) ;

    // 모두 맞는지 확인
    if(iter != iter_e)
        cout << *iter << endl ;
    if(iter != v.end())
        cout << *iter << endl ;
    return 0 ;
}
