#include <iostream>
#include <cstdio>

using namespace std ;

int main(){
  int N = 0; 	// 점의 개수. 
  cin >> N ;
  int *x = new int[N] ;
  int *y = new int[N] ;
  
  for(int i = 0 ; i < N ; ++i){
   	cin >> x[i] >> y[i] ; 
  }
  
// 원점을 기준으로 하면 
/* 반시계는 
cos th -sin th
sin th cos th       이고. 

cos th sin th
-sin th cos th 인데..


어떤 점을 기준으로 하면 뭐였지... 


*/

  
  // 시계 방향 출력
  cout << x[0] << ' ' << y[0] << endl ;
  for(int i = 1; i < N ; i++){
  	cout << (y[i]-y[0])+x[0] <<' ' <<  -(x[i]-x[0])+y[0] << endl ;
  }
  
  
  
  // 반시계 방향 출력
  cout << x[0] << ' ' << y[0] << endl ;
  for(int i = 1; i < N ; i++){
  	cout << -(y[i]-y[0])+x[0] << ' ' << x[i]-x[0]+y[0] << endl ;
  }
  
  
  
  delete[] x ;
  delete[] y ;
  return 0 ;
  
}
