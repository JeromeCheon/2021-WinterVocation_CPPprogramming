#include <iostream>
#include <cstdio>
#include <string>
using namespace std ;

// int main(){
// 	char c ;
//   cin >> c ;
//
//   printf("%d\n", c-97) ;
//
//   return 0 ;
//
// }

/* problem 1
int main(){
	char c ;
  cin >> c ;
  printf("%d\n", c-97) ;
  return 0 ;

}
*/
// int count = 0 ;
int N, M ;
int map[100][100] = {0, } ;
void go(){
    int cnt ;
  for(int i = 0 ; i < N ; i++){
  	for(int j = 0 ; j < M ; j++){
    	if(map[i][j] >= 1){
        if(map[i][j+1] == 1 && map[i+1][j] == 0){
          map[i][j] = 0 ;
        	map[i][j+1] += 1 ;		// 2, 3 등 숫자로 하고,  이따 한번 탐색할 때 다 더해
        }
      	else if(map[i][j+1] == 0 && map[i+1][j] == 1){
					map[i][j] = 0 ;
        	map[i+1][j] += 1 ;
        }
        else if(map[i][j+1] == 1 && map[i+1][j] == 1){
        	map[i][j] = 0 ;
        	map[i+1][j] += 1 ;
          map[i][j+1] += 1 ;
        }
        else{
        	map[i][j] = 0 ;
        }
    }
  }
  // 다시 map 탐색하면서 가중치 들어간 것들 개수 더해
  for(int i = 0 ; i < N ; i++){
  	for(int j = 0 ; j < M ; j++){
    	if(map[i][j] >= 2)
        	count++ ;
    }
  }

  cout << count << endl ;
}

int main(){
 	const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 } ;
	const int dx[8] = { 0, 1, 1, 1, 0 , -1, -1, -1 } ;

  cin >> N >> M ;
  for(int i = 0 ; i < N ; i++){
  	for(int j = 0 ; j < M ; j++){
    	cin >> map[i][j] ;		// map[4][5] test case 1
    }
  }

  count  = go() ;
  return 0 ;
}
