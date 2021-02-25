#include <iostream>
#include <list>
using namespace std ;
bool predicate(int n){
    return 10 <= n && n <=30 ;
}

int main(){
    list<int> lt ;
    lt.push_back(10) ;
    lt.push_back(20) ;
    lt.push_back(30) ;
    lt.push_back(10) ;
    lt.push_back(40) ;
    lt.push_back(50) ;
    lt.push_back(10) ;
    lt.push_back(10) ;
    list<int>::iterator iter ;
    for(iter = lt.begin() ; iter != lt.end() ; ++iter )
        cout << *iter << " " ;
    cout << endl ;

    // lt.remove(10) ; // 10 원소의 모든 노드를 제거
    lt.remove_if(predicate) ;
    for(iter = lt.begin() ; iter != lt.end() ; ++iter)
        cout << *iter << " " ;
    cout << endl ;

    return 0 ;
}
