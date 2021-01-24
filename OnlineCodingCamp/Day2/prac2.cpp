#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
// 난이도 3 :  독립 도시 문제
/*
    모든 도시들끼리 서로 직접 연결되어 있는 그래프는 -> 완전 그래프. 따라서 모든 정점들에 대해 간선이 존재하는 그래프.
    이런 문제를 클리크(clique) 문제라고도 해. 일반적으로 최대 클리크를 찾는 문제는 NP Complete 문제이지만, 이 문제는 N의 범위가 충분히 작기 때문에 시간 내에 풀 수 있다.
    클리크는 여러 방법으로 찾을 수 있는데 비트 마스크를 이용한 간단한 방법이 있다.

    비트 마스크는 자료구조의 일종. 참/거짓을 표현하기 위해 boolean 배열이 아닌 하나의 정수로 표현하는 자료구조.
    boolean 배열을 이용할 수 있는데 왜 굳이 비트마스크를 이용하는 지 궁금? 이는 정수를 이용한다는 점, 그 중에서도 자연수를 이용해서 배열의 indedx로 쓸수 있다는 장점 때문.
    이 문제의 입력은 처음부터 인접행렬인 상황. 즉 입력 자체를 그대로 받아 2차원 배열로 그래프를 표현할 수 있다.
*/
using namespace std ;
struct EDGE{
    int from, to ;
};

int num ;
int table[11][11] ;
vector<int> adj[11] ;
vector<EDGE> edges ;
int connect(int cur_city, int cur_edge){
    return 0 ;
}

int main(){
    memset(table, 0, sizeof(table)) ;
    cin >> num ;
    // adj.resize(num +1) ;
    for (size_t i = 1; i <= num; i++) {
        for (size_t j = 1; j <= num; j++) {
            cin >> table[j][i] ;
            // adj[j].push_back(i) ;
            // adj[i].push_back(j) ;
            edges.push_back({j, i}) ;
        }
    }
    return 0 ;

}
