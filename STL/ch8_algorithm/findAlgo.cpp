#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

bool pred(int n){
    return n > 35 ;
}
int main(){
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;

    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << " ";
    cout << endl ;

    vector<int>::iterator iter ;
    iter = find(v.begin(), v.end(), 20) ;
    if(iter != v.end())
        cout << *iter <<"을 찾다! " << endl ;
    iter = find_if(v.begin(), v.end(), pred) ;
    if(iter != v.end())
        cout << "순차열에서 35보다 큰 첫번째 원소 : " << *iter << endl ;
    return 0 ;
}
