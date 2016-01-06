#include <iostream>
#include <vector>
bool isPrime(std::vector<long> primes, long key, int high, int low = 0){
	if(low > high)	return false;
	int mid = (low + high) / 2;
	if( primes[mid] > key) return isPrime(primes, key, low, mid - 1);
	if( primes[mid] < key) return isPrime(primes, key, mid + 1, high);
	if( primes[mid] == key) return true;
}
bool isPrime(long n){
	if( n == 2) return true;
	if( n % 2 == 0 || n == 1) return false;
	for(int i = 3; i * i < n; i += 2)
		if( n % i == 0)	return false;
	return true;
}
int main(){
	int conseq_primes = 0;
	std::vector<long> primes;
	for(int i = 1; i < 1000000; i++)	if( isPrime( i ) ) primes.push_back( i );
	long result = 0, *primesum = new long[primes.size() + 1];
	primesum[0]=0;
	for(int i = 0; i < primes.size(); i++ )	primesum[i + 1] = primesum[i] + primes[i];
	for(int i = conseq_primes; i < primes.size(); i++){
		for(int j = i - (conseq_primes + 1); j >= 0; j--){
			if( primesum[i] - primesum[j] > primes[primes.size() - 1] )	break;
			if( isPrime(primes, primesum[i] - primesum[j], primes.size())){
				conseq_primes = i - j;
				result = primesum[i] - primesum[j];
			}
		}
	}
	std::cout<< result <<std::endl;
	delete [] primesum;
	return 0;
}
