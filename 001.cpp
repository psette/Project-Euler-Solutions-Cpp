#include <iostream>
int main(){
   	int sum = 0;
	for(int i = 3; i < 1000; i += 3) sum += i;
	for(int i = 5; i < 1000; i += 5) 
		if( i % 3 != 0)	sum += i;
   std::cout<< sum <<std::endl;
   return 0;
}