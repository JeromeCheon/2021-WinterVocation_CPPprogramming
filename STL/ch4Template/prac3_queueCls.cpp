#include <iostream>
#include <string>
using namespace std ;

template<typename T>
class Queue{
    T* buf ;
    int size ;
    int capacity ;
    int popidx ;
public:
    explicit Queue(int cap = 100) : buf(0), size(0), popidx(0), capacity(cap){
        buf = new T[capacity] ;
    }
    T operator[](int idx){
        return buf[idx] ;
    }
    void Push(T data){
        buf[size++] = data ;
    }
    bool Empty() const {
        return (buf == NULL) ? true : false ;
    }
    T Pop(){
        T item ;
        item = buf[popidx] ;
        buf[popidx] = 0 ;
        popidx++ ;
        return item ;
    }

};

int main(){
    Queue<int> q ;

    q.Push(10) ;
    q.Push(20) ;
    q.Push(30) ;

    if(!q.Empty())
        cout << q.Pop() << endl ;
    if(!q.Empty())
        cout << q.Pop() << endl ;
    if(!q.Empty())
        cout << q.Pop() << endl ;

    return 0 ;
}
