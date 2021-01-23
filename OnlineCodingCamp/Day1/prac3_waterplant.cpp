/*
트리 구조의 특성상 두 정점 사이를 잇는 경로가 유일하다는 점. 하나의 간선을 삭제하여 주어진 트리 구조를 두개의 트리구조로 나누면 경로를 자유로이 선택 가능
트리 구조를 둘로 나눈뒤 각 트리 구조에서 적절한 경로를 선택하고 경로 길이의 곱을 최대화하는 가장 쉬운 방법?
->>>>> 두 경로를 트리 구조에서 가장 긴 경로(트리의 지름)로 선택하는 것.
자 그럼 트리 구조를 어떻게 나눌 것이냐? 수학에서의 절대 부등식 중 산술평균, 기하평균이 있다. 근데 (a+b)/2 >= sqrt(ab) 와 같은 수식을 적용하기 위해선
본 문제의 정점의 수가 그리 많지는 않으니 완전탐색, 모든 간선을 하나씩 제거해보면서 답이 가장 큰 경우를 고를 수 있다.

1. 전체 간선 중 하나의 간선을 제거한다
2. 간선을 제거하고 나온 두 개의 트리 지름을 구한다.
3. 두 지름을 곱한 값을 이전에 구해둔 답과 비교하여 큰 값으로 유지한다.
4. 이 과정을 모든 간선을 하나씩 제거해보며 실행한다.

만약 트리 구조를 adjacent list로 표현했다면 간선을 직접 제거하는 것은 그리 좋은 방법이 아니다.
만약 adjacent matrix로 표현했다면 특정 간선을 쉽게 추가 및 삭제할 수 있지만, 지름을 구하고 모든 간선을 하나씩 제거해 보는 과정에서 시간복잡도가 너무 커
이 문제를 해결하기 위해 간선을 직접 삭제하지 않고 사용하지 않을 간선을 표시ㅣㅣ만 해준뒤 해당 간선을 사용할 때가 되었을 떄 사용하지 않고 넘어가려함.
즉, 단순히 간선을 저장하는 배열과 어떤 간선을 사용하지 않을지 간선의 번호를 관리해주는 변수를 이용하자.

if(사용하지 않는 간선의 시작점과 현재 정점이 같고, 사용하지 않는 간선의 끝점과 다음 이동할 점이 같음 |
    OR 사용하지 않는 간선의 끝점과 현재 정점이 같고, 사용하지 않는 간선의 시작점과 다음 이동할 점이 같음
) // 단 양방향 트리이기 때문에 위치를 바꿔서도 비교해봐야함!

트리에서 가장 멀리 떨어져 있는 두 정점 사이의 거리를 가리켜 트리의 지름이라고 함. 우리가 구하고자 하는 값은 두 개로 나누어진 트리에서 경로를 선택하고,
이 두 경로의 곱을 가장 크게 만들어야 하니 트리의 지름을 구하면 돼.
트리의 지름은 DFS나 BFS를 두번 사용하여 구할 수 있음. 먼저 하나의 정점을 잡고 이진탐색을 수행한뒤 시작한 정점에서 가장 멀리 떨어져있는 정점을 찾아.
이후 해당 정점에서 다시 DFS 또는 BFS를 수행하여 가장 멀리 떨어져있는 점을 찾으면 이제 두 점은 트리의 지름의 양끝점이 돼

이렇게 찾은 두 점이 트리의 지름이라는 걸 어떻게 확신할 수 있을까?? 처음 탐색을 시작한 정점과 첫 탐색에서 찾은 가장 먼 정점을 각각 a,b 라고 하자
나올 수 있는 케이스는 a가 지름에 속하거나 b가 지름에 속하거나 a, b 둘 다 속하지 않을 때.
1. a가 지름에 속하는 점이라면 a에서 가장 멀리 떨어진 b까지가 트리의 지름이 된다.
2. b가 지름에 속하는 점이라면 b부터 다시 탐색해서 찾은 가장 먼 점을 선택하면 돼
3. 두 점 모두 속하지 않을 때 지름의 양 끝점을 u,v라 하면 트리에서 두 정점 사이의 경로는 항상 유일하기 때문에 나올 수 있는 경우를 두가지로 좁힐 수 있다.

경로의 길이를 비교하기 위해 두 정점 사이의 경로의 길이를 d(a,b)라고 하면 다음과 같은 관계
d(c, b) >= d(c, u),d(c,v)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std ;
class EDGE {
public:
    int from ;
    int to ;
    // EDGE(int a, int b) : from(a), to(b) {}
};
int num = 0 ;
int dist[2020] ; // 거리 배열 for 지름 구할 때
bool check[2020] ; // 방문 체크 배열 for 지름 구할 때

vector<int> adj[2020] ; // 트리 구조를 인접 리스트로 표현하기 위해 vector container 사용
vector<EDGE> edges ;  // 간선 정보를 저장할 배열

//DFS
void dfs(int cur_pt, int cur_dist, int no_use){ // cur_pt : 현재 정점, cur_dist : 현재까지의 거리, no_use :사용 안할 간선
    if (check[cur_pt])  // 이미 방문했던 정점이라면
        return ;

    check[cur_pt] = 1;
    dist[cur_pt] = cur_dist ;
    for (int i = 0; i < adj[cur_pt].size(); i++) {
        // cur_pt와 연결된 모든 정점 확인
        if ((edges[no_use].from == cur_pt && edges[no_use].to == adj[cur_pt][i]) ||
         (edges[no_use].to == cur_pt && edges[no_use].from == adj[cur_pt][i] )) {
            continue ;
        }
        dfs(adj[cur_pt][i], cur_dist + 1 , no_use) ;
    }

}

int getDist(int no_use){ // 두 트리의 지름을 구해서 두 지름의 곱을 구해주는 함수. no_use는 사용안할 간선의 번호
    memset(dist, 0, sizeof(dist)) ;
    memset(check, 0, sizeof(check)) ;

    dfs(edges[no_use].from, 1 ,no_use) ; // DFS 1 수행
    int ans = 0, ansI = 0 ;
    for(int i = 1; i <=num ; i++)
        if(dist[i] > ans){
            ans = dist[i] ;
            ansI = i ;
        }
    memset(dist, 0, sizeof(dist)) ;
    memset(check, 0, sizeof(check)) ;

    dfs(ansI, 1, no_use) ; // 처음 시작한 정점에서 가장 멀리 떨어진 정점에서 다시 수행
    ans = 0 ;
    for(int i =1 ; i <=num ; i++)
        ans = max(ans, dist[i]) ;
    int ans1 = ans -1 ;

    memset(dist, 0, sizeof(dist)) ;
    memset(check, 0, sizeof(check)) ;

    // 두 번째 트리의 지름을 구함
    dfs(edges[no_use].to, 1, no_use) ;
    ans = 0 ; ansI = 0 ;

    for(int i=1 ; i<=num ; i++)
        if(dist[i] > ans)
            ans = dist[i], ansI = i ;
    memset(dist, 0 ,sizeof(dist)) ;
    memset(check, 0 , sizeof(check)) ;

    dfs(ansI, 1, no_use) ;
    ans = 0 ;

    for(int i=1; i <= num ; i++)
        ans = max(ans, dist[i]) ;
    int ans2 = ans -1 ;
    return ans1 * ans2 ;
}
int main(){
    cin >> num ;
    for (int i = 0; i < num - 1; i++) {
        int a, b ;
        cin >> a >> b ; // a, b를 입력 받아 인접 리스트 / 간선 정보에 저장
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
        edges.push_back({a, b}) ;
        // (edges.to).push_back( a) ;
        // (edges.from).push_back( b) ;
    }
    int ans = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        ans = max(ans, getDist(i)) ; // 모든 간선을 하나씩 지워보며 정답을 구함
    }
    cout << ans << endl ;

    return 0 ;

}
 /* 해설 모범 답안
 #include<bits/stdc++.h>
 using namespace std;
 struct EDGE {	//간선의 정보를 저장할 구조체
 	int from, to;
 };
 int n;	//정점의 개수
 int dist[2020];	//트리의 지름을 구할 때 사용하기 위한 거리 저장 배열
 bool chk[2020];	//트리의 지름을 구할 때 사용하기 위한 방문 체크 배열
 vector<int> adj[2020];	//트리 구조를 인접 리스트로 표현
 vector<EDGE> edges;	//간선 정보를 저장할 배열

 //DFS
 void go(int s, int w, int e) {	//s: 현재 정점, w: 현재까지 거리, e: 사용하지 않을 간선 번호
 	if (chk[s]) return;	//이미 방문한 정점이라면 탐색 중단
 	chk[s] = 1;	//현재 위치 방문 체크
 	dist[s] = w;	//현재 위치의 거리 기록
 	for (int i = 0; i < adj[s].size(); ++i) {	//현재 정점과 연결된 모든 정점 확인
 		if ((edges[e].from == s && edges[e].to == adj[s][i])	//만약 사용하지 않는 간선이라면 탐색 중단
 			|| (edges[e].from == adj[s][i] && edges[e].to == s)) continue;
 		go(adj[s][i], w + 1, e);
 	}
 }

 int GetD(int s) {	//두 트리의 지름을 구하여 두 지름의 곱을 구해주는 함수, s는 사용하지 않을 간선의 번호
 	memset(dist, 0, sizeof(dist));	//모든 정점의 거리를 0으로 초기화
 	memset(chk, 0, sizeof(chk));	//모든 방문 체크를 방문 안했음으로 초기화

 	go(edges[s].from, 1, s);	//DFS 수행(1)

 	int ans = 0, ansI = 0;	//DFS를 시작한 정점으로부터 가장 멀리 떨어진 점을 구함
 	for (int i = 1; i <= n; ++i)
 		if (dist[i] > ans)
 			ans = dist[i], ansI = i;

 	memset(dist, 0, sizeof(dist));
 	memset(chk, 0, sizeof(chk));

 	go(ansI, 1, s);	//처음 시작한 정점에서 가장 멀리 떨어진 정점에서 다시 DFS 수행
 	ans = 0;
 	for (int i = 1; i <= n; ++i)	//첫 번째 트리의 지름은 해당 정점에서 가장 멀리 떨어진 정점까지의 거리
 		ans = max(ans, dist[i]);
 	int ans1 = ans - 1;

 	memset(dist, 0, sizeof(dist));
 	memset(chk, 0, sizeof(chk));

 	//두 번째 트리의 지름을 구함
 	go(edges[s].to, 1, s);
 	ans = 0, ansI = 0;

 	for (int i = 1; i <= n; ++i)
 		if (dist[i] > ans)
 			ans = dist[i], ansI = i;

 	memset(dist, 0, sizeof(dist));
 	memset(chk, 0, sizeof(chk));

 	go(ansI, 1, s);
 	ans = 0;

 	for (int i = 1; i <= n; ++i)
 		ans = max(ans, dist[i]);

 	int ans2 = ans - 1;
 	return ans1 * ans2;
 }
 int main() {
 	scanf("%d", &n);
 	for (int i = 0; i < n - 1; ++i) {
 		int a, b; scanf("%d %d", &a, &b);
 		adj[a].push_back(b);	//a, b를 입력받아 인접 리스트 / 간선 정보에 저장
 		adj[b].push_back(a);
 		edges.push_back({ a, b });
 	}
 	int ans = 0;
 	for (int i = 0; i < edges.size(); ++i)	//모든 간선을 하나씩 지워보며 정답을 구함
 		ans = max(ans, GetD(i));
 	printf("%d", ans);
 }
 */
