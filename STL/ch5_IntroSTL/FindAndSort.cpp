#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
/* 이건 find 썼을 때
int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    vector<int>::iterator iter ;
    iter = find(v.begin(), v.end(), 20) ;
    cout << *iter << endl ;

    iter = find(v.begin(), v.end(), 100) ;
    if(iter == v.end())
        cout << "No exist 100 !" << endl ;

    return 0 ;
}*/
#include <list>

int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;
    list<int> lt ;
    lt.push_back(10) ;
    lt.push_back(20) ;
    lt.push_back(30) ;
    lt.push_back(40) ;
    lt.push_back(50) ;

    sort(v.begin(), v.end(), less<int>()) ; // less 연산 기준으로 정렬. 즉 오름차순
    for(vector<int>::iterator iter = v.begin() ; iter != v.end() ; ++iter )
        cout << *iter << endl ;
    sort(v.begin(), v.end(), greater<int>()) ; // greater 연산 기준으로. 즉 내림차순 
    for(vector<int>::iterator iter = v.begin() ; iter != v.end() ; ++iter )
        cout << *iter << endl ;
    cout << endl ;

    // sort(lt.begin(), lt.end()) ;    // error! list는 bidirectional iterator

    return 0 ;
}
