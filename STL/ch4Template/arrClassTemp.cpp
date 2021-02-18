/*
    클래스 템플릿은 클래스를 만들어내는 틀. 함수템플릿과 별반 다르지 않으나 함수에서 클래스로 바뀐 것.
    * Array(int cap): 생성자는 저장 가능한 최대 원소의 개수(cap)를 인자로 받아 메모리를 생성한다
    * ~Array() : destructor
    * Add(int data): Array 객체에 정수를 추가(저장)함
    * operator[](int idx): Array 객체의 idx 원소값을 반환
    * GetSize() : Array 객체의 원소 개수를 반환함
*/
#include <iostream>
#include <string>
using namespace std ;

class Array{
    int *buf ;
    int size ;
    int capacity ;
public:
    explicit Array(int cap=100): buf(0), size(0), capacity(cap){
        buf = new int[capacity] ;
    }
    ~Array(){delete[] buf ;}
    void Add(int data){
        buf[size++] = data ;
    }
    int operator[](int idx) const {
        return buf[idx] ;
    }
    int GetSize() const {return size ;}

};

int main(){
    Array arr ;
    arr.Add(10) ;
    arr.Add(20) ;
    arr.Add(30) ;

    for (size_t i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << endl ;
    }
    return 0 ;
}
