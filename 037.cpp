#include <iostream>
#include <cmath>
#include <vector>
bool isPrime(int n){
	unsigned int limit = sqrt(n) + 1;
	if( n == 2)		return true;
	if( n == 1 || n % 2 == 0)	return false;
	for( int i = 3; i <= limit; i += 2)
		if(n % i == 0)	return false;
	return true;
}
bool lrPrime(int n, std::vector<bool>& PrimeArr){
	int limit = log10(n), leftnum = n, rightnum = n;
	if(!PrimeArr[n])	return false;
	for(int i = 1; i <= limit; i++){
		leftnum /= 10;
		rightnum = n % (int)pow(10,i);
		if( !PrimeArr[leftnum] || !PrimeArr[rightnum] )	return false;
	}
	return true;
}
int main(){
	int count = 0, sum = 0;
	long long i = 11;
	std::vector<bool> PrimeArr;
	for(int i = 0; i < 1000000; i++)	PrimeArr.push_back(isPrime(i));
	while( count < 11){
		if( lrPrime(i,PrimeArr) ){
			count++;
			sum += i;
		}
		i++;
	}
	std::cout<< sum <<std::endl;
	return 0;
}
