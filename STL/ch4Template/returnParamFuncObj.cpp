#include <iostream>
#include <string>
using namespace std ;

template<typename retType, typename argType>
class Functor{
public:
    retType operator()(argType data){
        cout << data << endl ;
        return retType() ;
    }
};

int main(){
    Functor<void, int> functor1 ;
    functor1(100) ;
    Functor<bool, string> functor2 ;
    functor2("Hello!") ;

    return 0 ;
}
