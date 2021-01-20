#include <iostream>
#include <cstdio>

int main(){
	long long n, m ;
	long long count, mean ; 
	int i = 0; 
	unsigned long long output = 0UL ;
	scanf("%lld %lld", &n, &m) ;
	mean = (long long)((n+m) / 2) ;
	if( (n+m) % 2 == 0 ){
		count = m - n ;
		output = mean * (count + 1) ;
	}
	else{ 	
		mean = (long long)((m - n) / 2) + 1 ;
		output = mean * (n + m) ;
	}
	printf("%llu", output) ;

	return 0;
}
