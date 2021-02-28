#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    std::vector<int> v;

    for(int i = 0 ; i < 100 ; i++)
        v.push_back(rand() % 1000) ;
    nth_element(v.begin(), v.begin()+20, v.end()) ;

    cout << "v[greater 20 ea] : " ;
    for(vector<int>::size_type i = 0 ; i < 20 ; i++)
        cout << v[i] << " " ;
    cout << endl ;

    cout << "v[less 80 ea] : " ;
    for(vector<int>::size_type i = 20 ; i < v.size() ; i++)
        cout << v[i] << " " ;
    cout << endl ;
}
