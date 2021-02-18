#include <iostream>
#include <string>
using namespace std ;

template<typename T>
class Array{
    T *buf ;
    int size ;
    int capacity ;
public:
    explicit Array(int cap = 100): capacity(cap), buf(0), size(0){
        buf = new T[capacity] ;
    }
    void Add(T data){
        buf[size++] = data ;
    }
    T operator[](int idx) const {
        return buf[idx] ;
    }
    int getSize() const {
        return size ;
    }
};

int main(){
    Array<int> iarr ;
    iarr.Add(10) ;

    Array<double> darr ;
    darr.Add(.2) ;

    Array<string> sarr ;
    sarr.Add("damn wifi") ;

    return 0 ;
}
