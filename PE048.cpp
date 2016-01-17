#include <iostream>
int main(){
    long modulus = 10000000000, result = 0;
	for(int i = 1; i < 1000; i++){
		long temp = 1;
		for( int exponent = 1; exponent <= i; exponent++)	temp = (temp * i) % modulus;
		result = (result + temp) % modulus;
	}
	std::cout << result <<std::endl;
	return 0;
}