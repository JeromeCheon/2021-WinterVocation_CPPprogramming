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
    long *dp = new long(end+1) ;
    memset(&dp, 0, sizeof(dp)) ; // dp 배열 0으로 초기화
    for (int i = minji; i < end; i+=num) {
        if (i % 10 ==3 || i % 10 ==6 || i % 10 == 9) { // 3, 6, 9이면 박수 한번씩 추가
            dp[i] = dp[i/10] + 1 ;
            count = dp[i] ;
        }
    }
    cout << count << endl ;
    delete dp ;
    return 0;
}
