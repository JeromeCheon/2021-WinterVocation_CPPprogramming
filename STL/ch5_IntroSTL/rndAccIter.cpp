#include <iostream>
#include <vector>

using namespace std ;
/* vector random access iterator
int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    vector<int>::iterator iter = v.begin() ;
    cout << iter[0] << endl ;
    cout << iter[1] << endl ;
    cout << iter[2] << endl ;
    cout << iter[3] << endl ;
    cout << iter[4] << endl ;
    cout << endl ;

    iter += 2 ; // += 연산 가능
    cout << *iter << endl ; // * 연산자로 접근 가능
    cout << endl ;

    vector<int>::iterator iter2 = iter + 2 ;
    cout << *iter2 << endl ;

    return 0 ;
}*/

#include <deque>

int main(){
    deque<int> dq ;
    dq.push_back(10) ;
    dq.push_back(20) ;
    dq.push_back(30) ;
    dq.push_back(40) ;
    dq.push_back(50) ;

    deque<int>::iterator iter = dq.begin() ;
    cout << iter[0] << endl ;
    cout << iter[1] << endl ;
    cout << iter[2] << endl ;
    cout << iter[3] << endl ;
    cout << iter[4] << endl ;
    cout << endl ;

    iter += 2 ;
    cout << *iter << endl ;
    cout << endl ;

    deque<int>::iterator iter2 = iter +2 ;
    cout << *iter2 << endl ;

    return 0 ;
}
