#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    std::vector<int> v1;
    v1.push_back(50) ;
    v1.push_back(10) ;
    v1.push_back(30) ;
    v1.push_back(80) ;
    v1.push_back(60) ;

    std::vector<int> v2;
    v2.push_back(20) ;
    v2.push_back(70) ;
    v2.push_back(40) ;

    std::vector<int> v3(8);
    vector<int>::iterator iter_v3 ;
    iter_v3 = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()) ;
    sort(v3.begin(), v3.end()) ;
    for(std::vector<int>::size_type i = 0 ; i < v3.size() ; i++)
        cout << v3[i] << ' ' ;
    cout << endl ;

    return 0 ;
}
