#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std ;

struct EDGE{
    int from , to ;
};
int num ;
vector<int> adj[505] ;
vector<EDGE> edges ; // 사람간의 네트워크 표시
int dp[505] ;
int check[505] ;
void tree(/*int starter, */){
    // int& ans =
    int starter=0, sec = 0 ;
    cout << starter << sec << endl ;
    // 모두 연결이 안 됐으면 -1을 출력해야 함.
    int t = -1 ;
    cout << t << endl ;

}

int main(){
    cin >> num ;
    for (size_t i = 1; i <= num; i++) {
        int a=0, b=0 ;
        cin >> a >> b ;
        if (a!=0) {
            adj[i].push_back(b) ;
        }
    }
    tree() ;
    return 0 ;
}
