#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std ;
typedef long long ll ;
int table[1001][1001] ; // 둘다 전역변수로 선언 해 버리는거지
ll dp[1001][1001] ;
// 오른쪽, 아래쪽으로 움직이기 위한 배열이 필요하대.
int mvX[] = {1, 0} ;
int mvY[] = {0, 1} ;
// moving을 위한 함수 필요.
ll move(int x, int y, int num){
    ll& ans = dp[x][y] ; // long long type 참조 변수를 dp배열의 원소로 초기화
    if(~ans)
        return ans ; // res가 1이 아닌 수이면 해당 dp의 값을 반환해
    if (x == num-1 && y == num-1) { // 맨 오른쪽 아래에 도착했다면, 그 때는 0을 반환
        return dp[x][y] = 0 ;
    }
    ll tmp = 10000000000000 ; // 1e9처럼 해도 돼
    for (int i = 0; i < 2; i++) {
        int nx = x + mvX[i] ;
        int ny = y + mvY[i] ;
        if (0<= nx && nx < num && 0 <=ny && ny < num ) { // 다음 위치가 경계를 벗어나지 않는다면
            int diff = table[nx][ny] - table[x][y] ; // 높이 차이 계산
            tmp = min(tmp, move(nx, ny, num) + (diff > 0 ? diff : 0)); // 함수 재귀를 사용해서 지금 값과 밑, 오른쪽 거칠떄의 비용 중에 최소를 구해

        }
    }
    return ans = tmp ; //정답을 메모하고 반환
}


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
    memset(dp, -1, sizeof(dp)) ;
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N ; j++)
            cin >> table[i][j] ;
    }
    cout << go(0, 0, N) << endl ;
    // 특정 위치에서 가장 오른쪽 끝으로 이동하는 것이 한번 결정되면 두 번 다시 계산할 필요가 없다는 점,
    // 모든 위치에서 오르막 점수를 구하기 위해 다음 지점인 오른쪽과 아래 위치를 참조한다는 점.
    // 마지막으로 모든 위치에서 오르막 점수를 구하기 위해 같은 방법을 이용할 수 있다는 점.

    // long *table = new long*[N] ;   // 계단 높이를 저장할 테이블 2 dimension array 생성
    // ll *dp = new ll*[N] ;
    // for (int i = 0; i < N; i++){
    //     table[i] = new long[N] ;
    //     // memset(table, -1, ) // 왜 -1로 초기화를 한다고 하는거지 모범답안은???
    //     dp[i] = new ll[N];
    //
    // }
    //
    //
    //
    // /*for (int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N ; j++){
    //         cin >> table[j][i] ;
    //         //여기서 dp를 만들어 볼까.
    //         if (table[j][i] < table[j+1][i] ) { // 자기 밑의 값과 비교해서 밑의 값이 더 클 떄, 올라가는 거니까 증가.
    //             dp[j+1][i] = table[j+1][i] - table[j][i] ;
    //         }
    //         if (table[j][i] >= table[j+1][i] || table[j][i] >= table[j][i+1]) { // 밑이나 오른쪽 값이 더 작으면 그냥 내려가.
    //             if (table[j][i+1] >= table[j+1][i]) { // 오른쪽 값이 밑 값보다 크면? 밑의 값으로.
    //
    //             }
    //         }
    //     }
    // }*/
    // // dp 만들기
    //
    // // free memory
    // for (int i = 0; i < N; i++ )
    //     delete[] table[i] ;
    // delete[] table ;
    return 0 ;
}
/* 해설지 모범답안
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int board[1010][1010];	//각 위치의 높이를 저장할 배열
ll d[1010][1010];	//d[i][j] = (i, j)에서 출발하여 얻을 수 있는 오르막 점수의 최솟값
int n;
int dx[] = { 1, 0 };	//오른쪽, 아래를 이동하기 위한 배열
int dy[] = { 0, 1 };	//오른쪽, 아래를 이동하기 위한 배열

ll go(int x, int y) {	//x, y는 현재 위치
	ll& res = d[x][y];
	if (~res) return res;	//만약 현재 위치에 이미 방문하여 답을 구해놨다면(답이 -1이 아니라면) 답을 리턴
	if (x == n - 1 && y == n - 1) 	//가장 오른쪽 아래에 도착했다면 0을 반환
		return d[x][y] = 0;

	ll tmp = 1e9;
	for (int i = 0; i < 2; ++i) {	//오른쪽과 아래를 확인
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {	//다음 위치가 경계를 벗어나지 않는다면
			int cl = board[nx][ny] - board[x][y];	//높이차이 계산
			tmp = min(tmp, go(nx, ny) + (cl > 0 ? cl : 0));	//tmp에 다음 위치 중 최솟값을 저장
		}
	}
	return res = tmp;	//정답을 메모하고 반환
}
int main(){
	memset(d, -1, sizeof(d));	//모든 정답을 -1로 초기화
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);
	printf("%lld", go(0, 0));
	return 0;
}*/
