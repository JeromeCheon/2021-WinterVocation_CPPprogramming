#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main(){
    vector<int> v(10) ;
    vector<int>::iterator iter ;

    for(vector<int>::size_type i = 1 ; i <= v.size() ; i++)
        v[i-1] = 10 * i ;

    cout << "Before modifying the vector container : " << endl ;
    for(iter = v.begin() ; iter != v.end() ; iter++)
        cout << *iter << endl ;
    cout << endl ;

    reverse(v.begin(), v.begin()+5) ;

    cout << "After modifying the vector container : " << endl ;
    for(iter = v.begin() ; iter != v.end() ; iter++)
        cout << *iter << endl ;
    cout << endl ;

    return 0 ;
}
