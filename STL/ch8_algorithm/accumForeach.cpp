#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

class accum{
    int total ;
public:
    explicit accum(int init = 0):total(init) { }
    void operator()(int& n){
        total += n ;
        n = total ;
    }
};
int main(){
    vector<int> v ;
    v.push_back(1) ;
    v.push_back(2) ;
    v.push_back(3) ;
    v.push_back(4) ;
    v.push_back(5) ;

    cout << "v : " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl ;

    for_each(v.begin(), v.end(), accum(0)) ;
    cout << "v: " ;
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl ;
    return 0 ;
}
