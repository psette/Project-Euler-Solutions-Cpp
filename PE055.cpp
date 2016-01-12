#include <string>
#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <iostream>
bool isPalindrome( std::string input ){
	std::string temp = input;
	std::reverse(input.begin(), input.end());
	return (temp == input);
}
bool isLyrchel(int num){
	BigInteger number = num;
	for(int i = 0; i < 50; i++){
		std::string reversed = bigIntegerToString(number);
		std::reverse(reversed.begin(), reversed.end());
		BigInteger rev = stringToBigInteger(reversed);
		number += rev;
		std::string temp = bigIntegerToString(number);
		if(isPalindrome(temp))	return false;
	}
	return true;
}
int main(){
	int result = 0;
	for(int i = 10; i < 10000; i++)	if(isLyrchel(i))	result++;
	std::cout<< result <<std::endl;
	return 0;
}