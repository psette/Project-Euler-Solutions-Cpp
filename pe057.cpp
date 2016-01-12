#include <cmath>
#include "BigIntegerLibrary.hh"
#include <string>
int main(){
	int result = 0;
	BigInteger two = 2;
	BigInteger den = 1;
	BigInteger num = 0;
	for(int i = 0; i < 1000; i++){
		BigInteger temp = (two * den) + num;
		num = den;
		den = temp;
		if(bigIntegerToString(num + den).length() > bigIntegerToString(den).length())	result++;
	}
	std::cout<<result<<std::endl;
	return 0;
}