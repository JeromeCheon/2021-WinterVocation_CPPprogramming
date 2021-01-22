#include <iostream>
#include <string>
#include <memory.h>

#define MAX 5000001

using namespace std ;
int main(){
    // 3, 6, 9 게임 다시 해보자. 쉽게 생각하자. dp 이용하면 풀 수 있어.
    int num=0, minji=0 ;
    long end = 0;
    int count =0 ;
    cin >> num >> end >> minji ;
    long *dp = new long[end+1]() ;
    // 8 59, 4 이렇게 주어지면 일단 배열은 모든 수가 저장되어 있어야함. 그러려면 건너뛰면서 for문 도는게 아니라 싹다 돌아야 하네.
    // 근데 minji의 turn은 minji + (n-1)num
    for (int i = 1; i <= end; i++) {
        if (i / 10 != 0) {
            dp[i] = dp[i/10] ;
        }
        if (i % 10 ==3 || i % 10 ==6 || i % 10 == 9) { // 3, 6, 9이면 박수 한번씩 추가
            dp[i] = dp[i/10] + 1 ; // i가 만약 13이면 dp[1]의 값을 불러오겠네. 일단 3, 6, 9번 인덱스는 무조건 1씩 될거고.
            // count += dp[i] ;
        }

        // cout << dp[i] << " " ;
    }
    // cout << endl ;
    for (int i = minji; i <= end; i+=num) {
        count += dp[i] ;
    }
    cout << count << endl ;

    delete[] dp ;
    return 0;
}
