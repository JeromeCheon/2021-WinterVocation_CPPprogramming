#include <iostream>
using namespace  std ;

template<typename T>
class Stack{
    T* buf ;
    int size ;
    int capacity ;
public:
    Stack(int cap = 100): size(0), buf(0), capacity(cap) {
        buf = new T[capacity] ;
    }   // constructor
    ~Stack(){
        delete[] buf ;
    }  // destructor
    T operator[](int idx){
        return buf[idx] ;
    }
    void Push(T num){
        buf[size++] = num ;
    }
    bool Empty() const {
        return (buf == NULL) ? true : false ;
    }
    T Pop() {
        if (buf != NULL) {
            T tmp ;
            tmp = buf[size-1] ;
            buf[size--] = 0 ;
            return tmp ;
        }
    }
};



int main(){
    Stack<int> st ;

    st.Push(10) ;
    st.Push(20) ;
    st.Push(30) ;

    if(!st.Empty())
        cout << st.Pop() << endl ;
    if(!st.Empty())
        cout << st.Pop() << endl ;
    if(!st.Empty())
        cout << st.Pop() << endl ;
    return 0 ;
}
