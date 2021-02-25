#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

bool pred(int n){
    return 25 < n ;
}

int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    for(vector<int>::size_type i = 0 ; i<v.size() ; i++){
        cout << v[i] << " " ;
    }
    cout << endl ;

    // interval [v.begin, v.end) 에서 pred 적용
    int n = count_if(v.begin(), v.end(), pred) ;
    cout << "25보다 큰 원소의 개수: " << n << endl ;

    return 0 ;
}
