#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std ;

template<typename T>
struct Plus{
    T operator()(const T& left, const T& right) const {
        return left + right ;
    }
};

int main(){
    std::vector<int> v1(10);
    for(vector<int>::size_type i = 1 ; i <= v1.size() ; i++)
        v1[i-1] = i * 10 ;
    vector<int> v2(10), v3(10) ;
    vector<int>::iterator iter_v2, iter_v3 ;

    iter_v2 = copy(v1.begin(), v1.end(), v2.begin()) ;
    for(vector<int>::size_type i = 0 ; i < v2.size() ; i++)
        cout << v2[i] << ' ' ;
    cout << endl ;
    // generate(v3.begin(), v3.end(), Plus<int>(v1, v2)) ;
    // for_each(v3.begin(), v3.end(), Plus<int>()(v1, v2)) ;
    for(vector<int>::size_type i = 0 ; i < v3.size() ; i++){
        v3[i] = v1[i] + v2[i] ;
        cout << v3[i] << ' ' ;
    }
    cout << endl ;

    return 0 ;
}
