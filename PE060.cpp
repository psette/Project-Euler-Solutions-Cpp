#include <iostream>
#include <vector>
std::vector<bool> SieveOfEratosthenes(int n){
	bool prime[n+1];
	std::vector<bool> result;
    for ( int i = 0; i <= n; i++)   prime[i] = true;
	for (int j = 2; j * j <= n; j++){
		if (prime[j] == true)
		    for (int i = j * 2; i <= n; i += j)	prime[i] = false;
	}
	result.push_back(2);
	for (int i = 3; i <= n; i += 2)
	    if (prime[i])   result.push_back( i );
	return result;
}
int main(){
	std::vector primes = SieveOfEratosthenes(30000);
	
}