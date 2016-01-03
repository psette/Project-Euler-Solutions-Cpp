#include <iostream>
#include <cmath>
#include <vector>
bool isPrime(int n ){
	if( n == 2)		return true;
	if( n == 1 || n % 2 == 0)	return false;
	for( int i = 3; i <= sqrt(n) + 1; i += 2)
		if(n % i == 0)	return false;
	return true;
}
int hasfourprimes( int num ){
	int prime_factors = 0;
	bool prime_fac = false;
	while( num % 2 == 0) {
		prime_fac = true;
		num = num / 2;
	}
	if(prime_fac) prime_factors++;
	for( int divisor = 3; divisor <= sqrt(num); divisor += 2){
		prime_fac = false;
		while( num % divisor == 0){
			prime_fac = true;
			num = num / divisor;
		}
		if(prime_fac) prime_factors++;	
	}
	if( num > 2 ) prime_factors++;
	return (prime_factors >= 4);
}
int main(){
	int i = 3, count = 0;
	while( count < 4 ){
		hasfourprimes( i ) ? count++ : count = 0;
		i++;
	}
	std::cout<< i - 4 <<std::endl;	
}