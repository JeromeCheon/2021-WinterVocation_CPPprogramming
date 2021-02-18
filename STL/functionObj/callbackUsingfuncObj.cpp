#include <iostream>
#include <algorithm>
using namespace std ;

struct Functor1{
    void operator()(int n){
        cout << n << " " ;
    }

};
struct Functor2{
    void operator()(int n){
        cout << n*n << " ";
    }
};
struct Functor3{
    void operator()(int n){
        cout << "Integer :" << n << endl ;
    }
};

int main(){
    int arr[5] = {10,20,30,40,50} ;
    for_each(arr, arr+5, Functor1()) ;
    // for_each 알고리즘이 사용자 정의 타입도 전달 받을 수 있는데 이는 템플릿이 적용되었기 때문이다. 
    cout << endl <<endl ;
    for_each(arr, arr+5, Functor2()) ;
    cout << endl << endl ;
    for_each(arr, arr+5, Functor3()) ;
    return 0 ;
}
