/* 난이도 5 알록달록한 마을 만들기
    이 문제 해결을 위한 핵심 키워드는 트리 구조의 재귀적 속성. 트리 구조에 있는 특정 노드를 선택하고 해당 노드의 자손들을 모두 모으면 그역시 트리.
    접근 방법은 다음과 같다. d[i][c]라는 배열을 다음과 같이 정의
    ₩ i번 노드를 c번 색으로 칠했을 때 i번 노드를 루트 노드로 하는 서브 트리를 색칠하기 위한 최소 비용 ₩
    그래서 이전 노드의 색깔에 따라 현재 노드에 칠할 수 있는 색이 달라진다.
    d[c][i]를 구하는 방법은 단순히 i번 노드의 자식 노드들을 모든 색으로 칠해보며, 그 중 최솟값이 되는 색상을 선택한 경우만을 모아 더해야.
    풀이 키워드를 찾고 배열을 정의하는 것이 어려워 난이도가 높지만, 배열만 잘 정의하면 실제 구현은 큰 어려움 없이 할 수 있는 문제

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std ;

int dp[101010][11] ;
int check[101010] ; // 방문 확인을 위한 이진 배열
vector<int> cost ; // 색칠 비용
int color ; // 색의 개수
vector<int> adj[101010] ; // 트리 구조를 관리할 인접리스트

/*typedef node{
    int id ;
    int col ;
    Node* next ;
    Node* prev ;
}Node;*/

int connect(int cur_id, int cur_col){ // 현재 노드 번호, 현재 노드 색
    int& ans = dp[cur_id][cur_col] ;
    if(~ans)    return ans ;    // 이전에 구해 놓은 답 있으면
    ans = 0 ;   // 답을 0으로 초기화

    int sum = cost[cur_col] ; // 현재 노드의 색칠 비용을 더해줌
    check[cur_id] = 1 ; // 방문 체크
    for(int i = 0; i < adj[cur_id].size(); i++){ // 모든 자식 노드 확인
        int tmp = 2e9 ;
        int next = adj[cur_id][i] ;
        if(check[next])     continue ; // 이미 방문한 노드면 건너 뛰기
        for(int j=1; j<=color; j++){ // 현재 자식 노드를 1번부터 color번까지의 색으로 모두 칠해봄
            if(j == cur_col) continue ; // 현재 색과 같은 색이면 건너뛰기
            tmp = min(tmp, connect(next, j)) ; // 항상 최솟값이 되도록 유지

        }
        sum += tmp ; // 결과에 i번째 자식 노드를 통해 얻은 최솟값을 더해줌
    }
    ans += sum ; // 답을 기록
    check[cur_id] = 0 ; // 방문 체크 해제 후 탐색 종료
    return ans ;

}

int main(){
    int num = 0;
    memset(dp, -1, sizeof(dp)) ;
    // int color = 0 ;
    // int conn1 = 0, conn2 = 0 ;

    cin >> num >> color ;
    cost.resize(color + 1) ;
    for(int i=1; i <=color; i++)
        cin >> cost[i] ;
    for (int i = 0; i < num -1; i++) {
        int a, b ;
        cin >> a >> b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    int ans = 2e9 ;
    for(int i =1; i<=color ; i++) // 1번 노드를 기준으로 모든 색을 칠해보기
        ans = min(ans, connect(1, i)) ;
    cout << ans << endl ;
    // Node *place = new Node[num] ; // num 만큼 집을 만들기.
    // int *cost = new int[num]() ;
    // for (int i = 0; i < color; i++) {
    //     cin >> cost[i] ;
    // }
    // for (int i = 0; i < num; i++) {
    //     cin >> conn1 >> conn2 ;
    //     connect(&place[conn1], &place[conn2]) ;
    // }
    // 자 이제 색상 개수와 각 색상별 비용을 얻어서 저장했으니 이를 다뤄보자. 이걸... 구조체를 만들어서 링크드리스트를 써야 할 것 같은데...
    // delete[] cost ;
    // delete[] place ;
    return 0 ;
}
/* 해설 모범 답안
#include<bits/stdc++.h>
using namespace std;
int d[101010][11];
int chk[101010];	//방문 확인을 위한 배열
vector<int> cost;	//색칠 비용
int color;	//색의 개수
vector<int> adj[101010];	//트리 구조를 관리할 인접 리스트

int go(int s, int c) {	//s: 현재 노드 번호, c: 현재 노드의 색
	int& res = d[s][c];
	if (~res) return res;	//만약 이전에 구해둔 답이 있다면 답을 반환
	res = 0;	//답을 0으로 초기화

	int sum = cost[c];	//현재 노드의 색칠 비용을 더해줌

	chk[s] = 1;	//방문 체크
	for (int i = 0; i < adj[s].size(); ++i) {	//모든 자식 노드를 확인
		int tmp = 2e9, next = adj[s][i];
		if (chk[next]) continue;	//이미 방문한 노드라면 스킵
		for (int j = 1; j <= color; ++j) {	//현재 자식 노드를 1번부터 color번까지의 색으로 모두 칠해봄
			if (j == c) continue;	//현재 노드와 같은 색이라면 칠하지 않고 넘어감
			tmp = min(tmp, go(next, j));	//항상 최솟값이 되도록 유지
		}
		sum += tmp;	//결과에 i번째 자식 노드를 통해 얻은 최솟값을 더해줌
	}
	res += sum;	//답을 기록
	chk[s] = 0;	//방문체크 해제 후 탐색 종료
	return res;
}
int main() {
	memset(d, -1, sizeof(d));	//모든 답을 나올 수 없는 답(-1)으로 초기화
	int n; scanf("%d %d", &n, &color);
	cost.resize(color + 1);
	for (int i = 1; i <= color; ++i)
		scanf("%d", &cost[i]);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 2e9;
	for (int i = 1; i <= color; ++i)	//1번 노드를 기준으로 모든 색을 칠해봄
		ans = min(ans, go(1, i));
	printf("%d", ans);
}
*/
