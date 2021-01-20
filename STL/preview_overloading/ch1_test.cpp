#include <iostream>
#include <string>
#include <cstring>

using namespace std ;

class String{
    char* txt ;

public:
    String(){}
    String(const char* str) {
        // int len = strlen(str) +1 ;
        // txt = new char(len) ;
        strcpy(this->txt, str) ;

        cout << "constructor overloading and sentence is " << txt << endl ;
    }
    operator const char*() const{
        return txt ;
    }


    char* getter() const {return txt ;}
};
// const char* operator=(String &s){
//     return s.getter() ;
// }

int main(){
    String s("Hello!") ;
    const char* sz = s ; // sz.operator(s) ;  or (const char*)s 되도록
    cout << sz << endl ;

    return 0;
}
