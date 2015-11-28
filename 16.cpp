#include <iostream>
#include <cmath>
int main(){
	int result=0;
	unsigned long long num=(int)pow(2,1000);
	std::cout<<num; 
	while (num > 0) {
    	result+=num%10;
    	num/= 10;
	}
	std::cout<<result<<std::endl;
	return 0;
}