#include <iostream>

using namespace std ;

class Array{
    int *arr ;
    int size ;
    int capacity ;
public:
    Array(int cap=100) :arr(0), size(0), capacity(cap){
        arr = new int[capacity] ; // 생성자 오버로드 후 int 형 배열 객체를 capacity 만큼 생성
    }
    ~Array(){
        delete[] arr ;
    }
    void Add(int data){
        if (size < capacity)
            arr[size++] = data ;

    }
    int Size() const {
        return size ;
    }
    int operator[] (int idx) const{
        return arr[idx] ;
    }
    // 이건 읽기 쓰기 연산 모두 가능하게 하기 위해. 비 const 객체에 사용된다.
    int& operator[] (int idx){
        return arr[idx] ;
    }

};

int main(){
    Array ar(10) ;
    ar.Add(10) ;
    ar.Add(20) ;
    ar.Add(30) ;

    cout << ar[0] << endl ;
    cout << endl ;

    const Array& ar2 = ar ; // ar2는 값 쓰기가 안됨. const 로 선언했으니까!
    cout << ar2[0] << endl ;
    cout << endl ;

    ar[0] = 100 ; // ar.operator[] (int) 호출!
    //ar2[0] = 100 ; 이건 에러! 상수 객체(값)을 반환하므로 대입할 수없다.

    // for (size_t i = 0; i < ar.Size(); i++) {
    //     cout << ar[i] << endl ;
    //     // ar.operator[](i) ;
    // }
    return 0 ;
}
