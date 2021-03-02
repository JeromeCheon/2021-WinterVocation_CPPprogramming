#include <iostream>
#include <string>
using namespace std ;

int main(){
    string s("Hello!") ;
    char buf[100] ;

    // caution ! copy() doesn't include '\0' character at the end of the string
    s.copy(buf, s.length()) ;
    buf[s.length()] = '\0' ;
    cout << "An entire string[copy(buf, n)] : " <<  buf << endl ;
    s.copy(buf, 4, 2) ;
    buf[4] = '\0' ;
    cout << "sub string[copy(buf, n, off)] : " << buf << endl ;

    return 0 ;
}
