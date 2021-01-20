#include <stdio.h>
#include <stdlib.h>

int main(){
  unsigned long long num, input ;
  unsigned long long output, temp ;
  unsigned long long convert, count=0 ;
  
  int i ;
  scanf("%llu", &num) ;
  for(i=0;i<num; i++){
    scanf("%llu", &input) ;
    while(input > 0){
		convert = input % 2 ;
		//if((convert == 0) && (input > 2))
		//if(input > 2)
		if(convert == 0){
			count += 1 ;
		}
		else{
			count += 1 ;
			break ;
		}
		input /= 2;
	}
	printf("%llu\n", count) ;
	//printf("%llu\n",(long long)(count/2)) ;
  	count = 1 ;
  }
	return 0 ;
}
