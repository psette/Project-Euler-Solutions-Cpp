#include <iostream>
bool isPrime( int n ){
	if( n == 2) return true;
	if( n == 1 || n % 2 == 0)	return false;
	for (int i = 3; i * i <= n; i += 2)
		if( n % i == 0)	return false;
	return true;
}
int main(){
	int primes = 0, value = 1;
	for (; ;value += 2) {
		for (int i = 0; i < 4; i++) 
			if ( isPrime(value * value - i * value + i * 1))	primes++;
		if (value > 1 && primes * 5 < value ){
			std::cerr<< value <<std::endl;
			return 0;
		}	
	}
}