#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    std::vector<int> v;
    v.push_back(70) ;
    v.push_back(20) ;
    v.push_back(32) ;
    v.push_back(40) ;
    v.push_back(33) ;
    v.push_back(60) ;
    v.push_back(32) ;
    v.push_back(33) ;
    v.push_back(90) ;
    v.push_back(50) ;

    cout << "before sorting vector container : " << endl ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << ' ' ;
    cout << endl ;

    sort(v.begin(), v.end()) ;
    vector<int>::iterator p ;
    while(p != v.end()){
        p = unique(v.begin(), v.end()) ;
        v.erase(p, v.end()) ;
    }

    cout << "after sorting vector container : " << endl ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << ' ' ;
    cout << endl ;
    return 0 ;
}
