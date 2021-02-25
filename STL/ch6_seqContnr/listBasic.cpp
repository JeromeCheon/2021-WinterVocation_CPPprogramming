#include <iostream>
#include <list>
using namespace std ;

int main(){
    list<int> lt ;
    lt.push_back(10) ;
    lt.push_back(20) ;
    lt.push_back(30) ;
    lt.push_back(40) ;
    lt.push_back(50) ;

    list<int>::iterator iter = lt.begin() ;
    list<int>::iterator iter2 ;
    ++iter ;
    ++iter ;
    iter2 = lt.erase(iter) ; // iter(30) 의 원소 제거
    for(iter = lt.begin() ; iter != lt.end() ; ++iter){
        cout << *iter << " " ;
    }
    cout << endl ;

    cout << "iter2 : " << *iter2 << endl ;
    iter = iter2 ;
    iter2 = lt.insert(iter, 300) ;
    // lt.push_front(100)   ;
    // lt.push_front(200) ;

    for(iter = lt.begin() ; iter != lt.end() ; ++iter){
        cout << *iter << " " ;
    }
    cout << "iter2 : " << *iter2 << endl ;

    return 0 ;
}
