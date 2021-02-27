#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main(){
    vector<int> v1 ;
    v1.push_back(10) ;
    v1.push_back(20) ;
    v1.push_back(30) ;
    v1.push_back(40) ;
    v1.push_back(50) ;

    vector<int> v2 ;
    v2.push_back(40) ;
    v2.push_back(80) ;
    v2.push_back(20) ;

    cout << "v1 : " ;
    for(vector<int>::size_type i = 0 ; i < v1.size() ; i++)
        cout << v1[i] << " " ;
    cout << endl ;
    cout << "v2 : " ;
    for(vector<int>::size_type i = 0 ; i< v2.size() ; i++)
        cout << v2[i] << " " ;
    cout << endl ;

    vector<int>::iterator iter ;
    iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end()) ;
    // v1의 순차열에서 v2의 순차열 원소가 첫 번째로 발견되는 위치는 20이므로 20의 반복자를 반환
    // 또한 pred를 정의해서 마지막에 ,pred)를 붙여 쓸 수도 있다. 
    if(iter != v1.end())
        cout << "iter = " << *iter << endl ;

    return 0;

}
