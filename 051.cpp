#include <iostream>
#include <vector>
#include <string>
bool isPrime( long n ){
	if( n == 2)	return true;
	if( n == 1 || n % 2 == 0)	return false;
	for(int i = 3; i * i <= n; i++) if( n % i == 0)	return false;
	return true;
}
int nextPrime( int n ){
	while( !isPrime(n))	n += 2;
	return n;
}
bool eightPermutes( long n ){
	std::string num;
	bool flag = true;
	int count = 0, position;
	for( int i = 0; i < num.size(); i++ ){
		for(int j = 1; j < 10; j++){
			if( num[i] == j)	continue;
			std::string temp = num;
			temp[i] = j;
			if( isPrime(stol(temp) )	count++;
		}
	}
}
int main(){


}