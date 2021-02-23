#include <iostream>
#include <string>
using namespace std ;

template<typename iterT, typename func> // For_each<int, void (*)(int)>() | For_each<string, void (*)(string)>()
void For_each(iterT begin, iterT end, func fp){
    while(begin != end){
        fp(*begin++) ;
    }
}
/* 이것도 하나로 묶을 수 있어! template으로!
void PrintInt(int n){
    cout << n << " " ;
}
void PrintString(string data){
    cout << data << " " ;
}*/
/* 2nd method
template<typename T>
void Print(T data){
    cout << data << ' ' ;
}
*/
template<typename T>
struct PrintFunctor{
    string sep ;
    explicit PrintFunctor(const string &rhs=" "): sep(rhs){}
    void operator()(T data) const {
        cout << data << sep ;
    }
};

int main(){
    int arr[5] = {10, 20, 30, 40 ,50} ;
    // For_each(arr, arr+5, PrintInt) ; // 1. print Integer values
    // For_each(arr, arr+5, Print<int>) ;  // 2. using function object
    For_each(arr, arr+5, PrintFunctor<int>()) ;
    cout << endl ;

    string sarr[3] = {"Hello", "Universe", "HGU"} ;
    // For_each(sarr, sarr+3, PrintString) ;    // 1. just using different Print function
    // For_each(sarr, sarr+3, Print<string>) ; // 2. using function object
    For_each(sarr, sarr+3, PrintFunctor<string>("*\n")) ;
    cout << endl ;
    return 0 ;
}
