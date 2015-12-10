#include <iostream>
#include <cmath>
bool isprime(int x);
int main(){
	int max=0;
	for(int i=1;i<(int)sqrt(600851475143);i++){
		if(600851475143%i!=0){
			continue;
		}
		if(isprime(i)){
			max=i;
		}
	}
	std::cout<<max<<std::endl;
	return 0;
}
bool isprime(int x){
	for(int i=2;i<x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}