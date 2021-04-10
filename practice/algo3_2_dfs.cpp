#include <iostream>
#include <cstdio>
using namespace std ;
const int MAX = 200 ;

int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, 1, 0, -1} ;

int map[MAX][MAX] = {0, };
int N, M ;
void dfs(int x, int y){
    int x_co, y_co ;

    for (int i = 0; i < 4; i++) {
        x_co = x + dx[i] ;
        y_co = y + dy[i] ;
        if (x_co >= 0 && y_co >= 0 && x_co < N && y_co < N && map[x_co][y_co] == 1) {
            dfs(x_co, y_co) ;
        }
    }
}
int main(){
    int cnt = 0 ;
    cin >> N >> M ;

    for(int i = 0 ; i < N ; i++){
    	for(int j = 0 ; j < M ; j++){
      	cin >> map[i][j] ;		// map[4][5] test case 1
      }
    }
    for(int i = 0 ; i < N ; i++){
    	for(int j = 0 ; j < M ; j++){
            cnt++ ;
      	    dfs(i, j) ;	// map[4][5] test case 1
      }
    }
    cout << cnt << endl ;
    return 0 ;
}
