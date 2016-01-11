#include <iostream>
#include <vector>
bool isPrime(int n){
	if( n == 2) return true;
	if( n % 2 == 0 || n == 1) return false;
	for(int i = 3; i * i <= n; i += 2)	if( n % i == 0)	return false;
	return true;
}
int main(){
	unsigned int conseq_primes = 0, bigPrime = 0;
	std::vector<long> primes;
	for(int i = 2; i < 1000000; i++)
		if(isPrime( i )) primes.push_back( i++ );
	for(int i = 0; i < primes.size(); i++) {
		unsigned int sum = 0, j = i;
		while(sum < primes[ primes.size() - 1 ]) {
			sum += primes[j++];
			if ( sum > bigPrime && j - i > conseq_primes && isPrime(sum) ) {
				bigPrime = sum;
				conseq_primes = j - i;

			}
		}
	}
	std::cout<< bigPrime <<std::endl;
	return 0;
}