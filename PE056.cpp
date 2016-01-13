#include "BigIntegerLibrary.hh"
#include <iostream>
int digitSum(std::string input){
	int result = 0;
	for( int i = 0; i < input.length(); i++)	result += input[i] - '0';
	return result;
}
int main(){
	int max = 0;
	for(int i = 1; i < 100; i++){ 
		BigUnsigned base = i;
		for(int exponent = 1; exponent < 100; exponent++){
			base *= exponent;
			int digits = digitSum(bigIntegerToString(base));
			if( digits > max) max = digits;
		}
	}
	std::cout<< max <<std::endl;
	return 0;
}
