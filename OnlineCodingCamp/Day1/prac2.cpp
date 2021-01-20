#include <iostream>

using namespace std ;

int main(){
    // N x N 크기의 격자판 -> 이만큼의 배열을 만들자!
    int N ;

    long min ;
    long height ;
    cin >> N ;
    if (N<2 || N>1000) {
        exit(1) ;
    }
    long table[][] = new long[1001][1001] ;   // dp 배열 생성

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N ; j++){
            cin >> table[j][i] ;
        }
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N ; j++){
            cout << table[j][i] ;
        }
    }
    return 0 ;
}
