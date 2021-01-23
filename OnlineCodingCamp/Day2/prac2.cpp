#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

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
