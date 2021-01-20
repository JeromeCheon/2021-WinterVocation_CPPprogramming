#include <iostream>
#define MAX 5000001
using namespace std;

int main() {
    // 3 6 9가 k번 들어가면 k번 만큼의 박수를 쳐야한다.
    int num, C ;
    long End ;
    int ans = 0 ;
    cin >> num >> End >> C ;
    // handling error
    if (num > 1000 || num < 2 || End >= MAX || End < 5 || C > num || C < 1) {
        exit(1) ;
    }
    // [모범 답안 1] dp로 풀어야함!
    int *dp = new int[MAX] ;
    for (int i = 1; i <= MAX; i++) { // 1부터 500만까지 모든 답을 구하기 위해 반복
        int current = i % 10 ; // 현재 숫자의 가장 마지막 자리를 저장
        dp[i] = dp[i/10] ; // 현재 숫자의 마지막 자리를 포함하지 않는 답을 가져옴
        if (current != 0 && current % 3 == 0) { // 3, 6, 9 이면
            ++dp[i] ;
        }
    }
    for (int i = C; i < End; i+=num) {
        ans += dp[i] ;
    }
    cout << ans << endl ;
    /*
    for (long i = 1; i < End; i+=num) {
        int turn = C + i - 1 ; // i = i + num
        if (turn > End)     break ;
        // turn = 30일 때
        cout << "minji's turn : " << turn << endl ;

        if(turn % 3 == 0){
            if(turn % 10 == 0){
                // 30, 60, 90일 때
                while ((turn % 10) != 0 ) {
                    turn /= 10 ;
                }
            }
            if((turn % 10 == 3) || (turn % 10== 6) || (turn % 10 == 9)){ // 일의 자리수 3 6 9에 걸리면
                int tmp = turn ;
                if ((turn % 3 == 0) && (turn / 10 != 0)) { // 이건 특별 케이스로 더 세야. 10 초과하는 33 36 이런거 일떄.


                    while (tmp !=0 ) {
                        tmp /= 10 ;
                        ans++ ;
                    }
                }
                ans++ ;
            }
        }

        cout << "loop (" << i << ") , ans = "<< ans << endl;
    }
    cout << ans << endl ;
    */
	return 0;

}
