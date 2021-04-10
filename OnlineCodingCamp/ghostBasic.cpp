#include <iostream>
#include <string>
// #include <cstdio>

using namespace std ;

struct Dict{
    char c;
    int count
};

int main(){
    Dict dict[26] ;   // 각 원소별로 'a'~ 'z'까지를 지칭하며, 해당 하는 인덱스에 값을 저장할 것.
    for(int i = 'a',j=0 ; i <= 'z'; i++,j++){
        dict[j].c = i ;
        dict[j].count = 0 ;
    }

    string s ;
    getline(cin, s) ;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i] == dict[j].c) {  // dictionary에 매칭 되는게 있으면 count 증가
                dict[j].count += 1 ;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if(dict[i].count != 0)
            cout << dict[i].c << ":" << dict[i].count << endl ;
    }
    return 0 ;
}
