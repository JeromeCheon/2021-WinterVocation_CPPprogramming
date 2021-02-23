/*
#include <iostream>
#include <stack>

using namespace std ;

int main(){
    stack<int> st ;
    st.push(10) ;
    st.push(20) ;
    st.push(30) ;

    cout << st.top() << endl ;
    st.pop() ;
    cout << st.top() << endl ;
    st.pop() ;
    cout << st.top() << endl ;
    st.pop() ;

    if(st.empty())
        cout << "No data in stack !" << endl ;

    return 0 ;
}
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

int main(){
    stack<int, vector<int> > st ; // vector 컨테이너를 이용한 stack 컨테이너 생성
    st.push(10) ;
    st.push(20) ;
    st.push(30) ;

    cout << st.top() << endl ;
    st.pop() ;
    cout << st.top() << endl ;
    st.pop() ;
    cout << st.top() << endl ;
    st.pop() ;
    if(st.empty())
        cout << " no data in stack! " << endl ;
    return 0 ;
}
