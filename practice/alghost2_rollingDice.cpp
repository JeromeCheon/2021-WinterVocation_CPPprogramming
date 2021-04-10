#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std ;

struct Point{
    int x;
    int y;
    explicit Point(int _x, int _y) : x(_x), y(_y){}
};
int map[23][23] = {0,};
int dice[6] = {0} ;
int N, M ;
void move(Point* pt, int direction){
    if (abs(pt->x) == M || abs(pt->y) == N ) {
        /* code */
    }
    switch (direction) {
        case 1:
            dice[]
            break;
        case 2:
            break ;
        case 3:
            break ;
        default:
            break ;
    }
}


int main(){
    // 크기 M x N
    int x, y, K ;

    cin >> N >> M >> x >> y >> K ;
    int *direct ;
    int *upside ;
    direct = (int*)malloc(sizeof(int)*K) ;
    upside = (int*)malloc(sizeof(int)*K) ;
    memset(direct, 0, sizeof(int)) ;
    memset(upside, 0, sizeof(int)) ;
    Point pt(x, y) ;
    /* direction                앞
        3
    2       1             왼옆   위    오른옆
        4                       뒤
                                밑
    */
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> map[i][j] ;

        }
    }
    for(int i = 0 ; i < K ; i++){
        cin >> direct[i] ;
        move(&pt, direct[i]) ;

    }
    // print the output
    for (int i = 0; i < K; i++) {
        cout << upside[i] << endl ;
    }
    free(direct) ;
    free(upside) ;
    return 0 ;

}
