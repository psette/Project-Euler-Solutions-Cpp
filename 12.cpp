#include <iostream>
#include "math.h"
int count(int n);
int main(){
	int num = 0, i = 1;
	while(count(num)<500){
		num += i;
		i++;		
	}
	std::cout<<num<<std::endl;	
return 0;
}
int count(int n){
	int c=0;
	int sqr = sqrt(n);
	for( int i = 1; i <= sqr; i++){
		if(n % i == 0){
			c += 2;
		}
	}
	return c;
}