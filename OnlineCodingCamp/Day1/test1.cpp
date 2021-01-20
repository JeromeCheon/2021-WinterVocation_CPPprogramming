#include <iostream>
#include <string>
#include <algorithm>

#define MAX 100000

using namespace std;

int main() {
    // 승철이는 총 N화의 에피소드를 보았다. N은 1과 10만 사이의  자연수 -> unsigned long
    // 같은 에피소드를 두번 보지는 않았다. -> 한번만.
    // 연속적인 수열인지 판별하는 프로그램 완성하기
    char* input ;
    unsigned long count = 0;
    unsigned long N[MAX] = {0, };
    bool indicator = true ;
    cin >> count ;

    // fgets(input, MAX , stdin) ;
    for(int i=0; i<count ; i++){
        cin >> N[i] ;
    }

    sort(N, N+count) ;

    // 만약 수열이 성립하려면 1 2 3 4 5이렇게 했을 때
    for (int i = 0; i+1 < count; i++) {
        if((N[i+1] - N[i] != 1) && (N[i+1] != 0)){
            // cout << N[is+1] << N[i] << endl;
            indicator = false ;
            break ;
        }
    }
    if (indicator) { // 이게 true이면 yes 출력
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl ;

    return 0;
}
