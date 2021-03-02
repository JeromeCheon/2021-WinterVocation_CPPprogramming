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

    cout << "before removing an element : " << endl ;
    vector<int>::iterator iter ;
    for(iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << endl ;
    cout << endl ;

    vector<int>::iterator iter_end ;
    iter_end = remove(v.begin(), v.end(), 30) ;
    v.erase(iter_end, v.end()) ;    // size까지 줄여줘. 

    cout << "after removing an element : " << endl ;
    for(iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << endl ;
    cout << endl ;

    return 0 ;
}
