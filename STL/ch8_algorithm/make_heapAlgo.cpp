#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;
    v.push_back(60) ;

    cout << "v: " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << ' ' ;
    cout << endl ;

    make_heap(v.begin(), v.end()) ;
    cout << "v[make heap] : " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << ' ' ;
    cout << endl ;

    // push_heap() 써보기
    v.push_back(35) ;
    cout << "add 35 into v sequence : " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<' ' ;
    cout << endl ;

    push_heap(v.begin(), v.end()) ;     // make_heap 해도 돼
    cout << " perform the operation v[add heap] : " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<' ' ;
    cout << endl ;

    // pop_heap(v.begin(), v.end()) ;
    // cout << " perform the operation v[remove heap] : " ;

    // sort the sequence
    sort_heap(v.begin(), v.end()) ;
    cout << " perform the operation v[sort heap] : " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] <<' ' ;
    cout << endl ;

    return 0 ;
}
