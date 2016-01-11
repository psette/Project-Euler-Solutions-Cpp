#include <iostream>
#include <vector>
void mergesort(std::string& input, int low, int high) {
	if (low >= high - 1)	return;
	int mid = (low + high) / 2;
	mergesort(input, low, mid);
	mergesort(input, mid, high);
	int l1 = low, h1 = mid, l2 = mid, h2 = high;
	std::string temp;
	while (l1 < h1 && l2 < h2)	input[l1] < input[l2] ? temp += input[l1++] : temp += input[l2++];
	while (l1 < h1)	temp += input[l1++];
	while (l2 < h2)	temp += input[l2++];
	for (int i=0; i<temp.size(); i++) input[i + low] = temp[i];
}
bool isInPrimeVec(std::vector<int> primes, int key, int low, int high){
	if(low > high)	return false;;
	int mid = (low + high) / 2;
	if( primes[mid] > key) return isInPrimeVec(primes, key, low, mid - 1);
	if( primes[mid] < key) return isInPrimeVec(primes, key, mid + 1, high);
	if( primes[mid] == key) return true;
}
bool isPrime(int n ){
	if( n == 2)		return true;
	if( n == 1 || n % 2 == 0)	return false;
	for( int i = 3; i * i <= n; i += 2)
		if(n % i == 0)	return false;
	return true;
}
bool isPermute(std::string a, std::string b){
	mergesort( a, 0, a.length() );
	mergesort( b, 0, b.length() );
	return a == b;
} 
int main(){
	long result = 0;
	std::vector<int> primes;
	for( int i = 1489; i < 10000; i++)	if(isPrime(i)) primes.push_back(i);
	for( int i = 0; i < primes.size(); i++){
		for( int j = i + 1; j < primes.size(); j++){
			int temp = 2 * primes[j] - primes[i];
			if(temp >= primes[ primes.size() - 1 ])	break;
			if(isPrime(temp) ){
				if( isPermute( std::to_string(primes[i]), std::to_string(primes[j]) ) && isPermute( std::to_string(primes[i]), std::to_string(temp) ) ){
					result = stol(std::to_string(primes[i]) + std::to_string(primes[j]) + std::to_string(temp) );
					std::cout<< result <<std::endl;
					return 0;
				}
			}
		}
	}
}