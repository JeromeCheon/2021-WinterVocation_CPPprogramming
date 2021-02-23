#include <iostream>
#include <string>
using namespace std ;

template<typename T>
class ObjectInfo{
    T data ;
public:
    ObjectInfo(const T &rhs): data(rhs){}
    void Print(){
        cout << "Type :" << typeid(data).name() << endl ;
        cout << "Size :" << sizeof(data) << endl ;
        cout << "value : " << data << endl ;
        cout << endl ;
    }
};
// T를 string으로 특수화(클래스 탬플릿 특수화)
template<>
class ObjectInfo<string>{
    string data ;
public:
    ObjectInfo(const string &rhs):data(rhs) {}

    void Print(){
        cout << "type :" << "string" << endl ;
        cout << "string length: "<< data.size() << endl ;
        cout << "value: " << data ;
        cout  << endl ;
    }
};

int main(){
    ObjectInfo<int> d1(10) ;
    d1.Print() ;

    ObjectInfo<double> d2(5.5) ;
    d2.Print() ;

    // ObjectInfo<string> d3("Hello") ;
    ObjectInfo<string> d3("Hello") ;
    d3.Print() ;

    return 0;
}
