#include <iostream>
#include <string>
using namespace std ;

// template<typename T>
template<typename T=int , int capT=100> // int, 100 default hyperparameter 지정
class Array{
    T *buf ;
    int size ;
    int capacity ;
public:
    // explict Array(int cap=100): buf(0), size(0), capacity(cap){
    explict Array(int cap=capT): buf(0), size(0), capacity(cap)
        buf = new T[capacity] ;
    }
    ~Array(){
        delete[] buf ;
    }
    void Add(T data){
        buf[size++] = data ;
    }
    T operator[](int idx) const {
        return buf[idx] ;
    }
    int getsize() const{
        return size ;
    }

};

int main(){
    // Array<int> iarr ;
    Array<> iarr ; // 디폴트 매개변수 값 int , 100 사용.
    iarr.Add(10) ;

    Array<double> darr ; // 디폴트 매개변수 값 100 사용
    darr.Add(.2) ;

    Array<string> sarr ; // 디폴트 매개변수 값 사용 안함
    sarr.Add("damn wifi") ;

    return 0 ;
}
