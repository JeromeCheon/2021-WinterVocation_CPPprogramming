#include <iostream>
#include <string>

using namespace std ;

class String{
    char* txt ;
public:
    String(){
        cout << "constructor" << endl ;
    }
    String(const char* str){
        cout << "constructor(const char*)" << endl ;
        txt = new char(strlen(str)+1) ;
        strcpy(this->txt, str) ;
    }
    // 복사 생성자
    // String(const String &rhs){
    //     cout << "called copy cons" << endl ;
    //     txt = new char(strlen(rhs.txt)) ;
    //     strcpy(this->txt, rhs.txt) ;
    // }
    /*
    void operator=(const char* str){
        strcpy(this->txt, str) ;
    } 이게 얕은 복사? */

    // 이게 모범 답안! 깊은 복사 수행하기 위한 사용자 정의 복사 대입연산자.
    
    const String& operator=(const String &rhs){
        delete[] txt ;
        txt = new char[strlen(rhs.txt)+1] ;
        strcpy(txt, rhs.txt) ;
        return *this ;
    }
    operator const char* (){
        return this->txt ;
    }
    ~String(){
        delete[] txt ;
        cout << "destructor" << endl ;
    }
};

int main(){
    const char* sz = "Hello!" ;
    String s("Hi~!") ;
    s = sz ;
    cout << s << endl ;
}
