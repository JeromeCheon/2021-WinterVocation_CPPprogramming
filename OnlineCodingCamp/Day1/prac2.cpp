#include <iostream>

using namespace std ;

int main(){
    // N x N 크기의 격자판 -> 이만큼의 배열을 만들자!
    int N ;
    //높이는 100만 이하의 자연수 -> long이나 unsigned long써야.
    long min ;
    long height ;
    cin >> N ;
    if (N<2 || N>1000) {
        exit(1) ;
    }
    long table[1001][1001] = {0,} ;
    long dp[][] = table ;
    // long *table = new long[N]() ;   // dp 배열 생성
    // for (size_t i = 0; i < N; i++) {
    //     *table = new long[N][i]() ;
    // }
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N ; j++){
            cin >> table[j][i] ;
            //여기서 dp를 만들어 볼까.
            if (table[j][i] < table[j+1][i] ) { // 자기 밑의 값과 비교해서 밑의 값이 더 클 떄, 올라가는 거니까 증가.
                dp[j+1][i] = table[j+1][i] - table[j][i] ;
            }
            if (table[j][i] >= table[j+1][i] || table[j][i] >= table[j][i+1]) { // 밑이나 오른쪽 값이 더 작으면 그냥 내려가.
                if (table[j][i+1] >= table[j+1][i]) { // 오른쪽 값이 밑 값보다 크면? 밑의 값으로.
                    /* code */
                }
            }
        }
    }
    // dp 만들기
    for (int i = 1; i < ) {
        /* code */
    }
    // delete[] table ;
    return 0 ;
}
