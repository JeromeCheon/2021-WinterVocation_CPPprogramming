/* 색종이 문제

*/
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>

#define SPACE 10000

using namespace std ;

int main(){
    int T ;
    short N ; // 색종이의 수 : 1 ~ 100
    short num1 = 0, num2 = 0;
    int space[100][100] ;
    cin >> T ;
    int* result = new int[T+1] ;

    for (int i = 0; i < T; i++) { // 테스트 케이스 개수 만큼
        memset(space, 0, sizeof(space)) ;
        cin >> N ; // 색종이의 수 입력 받아.
        for (short j = 0; j < N; j++) {
            cin >> num1 >> num2 ; //    색종이의 범위는 num1+10 , num2 +10
            if(num1+10 > 100 || num2+10 > 100)
                exit(1) ;
            for (int k = num1; k < num1+10; k++) {
                for (int l = num2; l < num2+10; l++) {
                    if(space[l][k] == 0){ // 비어있으면 색종이로 덮어야지
                        space[l][k] = 1 ;
                        result[i] += 1 ;
                    }
                }
            }
        }
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl ;
    }
    return 0;
}
