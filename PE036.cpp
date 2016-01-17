#include <iostream>
#include <string>
#include <sstream>
bool isPalindrome(std::string num){
	if(num.length() == 1)	return true;
	for( int i = 0; i <= (int)(num.length() / 2); i++)
		if(num[i] != num[num.length() - 1 - i])	return false;
	return true;
}
std::string binary(std::string n){
    unsigned long long rem = 0, i = 1, binary = 0, num = 0;
    std::stringstream buffer;
    buffer << n;
    buffer >> num;
    buffer.clear(); buffer.str("");
    std::string result;
    while (num != 0){
        rem = num % 2;
        num /= 2;
        binary += rem * i;
        i *= 10;
    }
 	buffer << binary;
 	buffer >> result;
    return result;
}
int main(){
	int sum = 0;
	for( int i = 1; i < 1000000; i++){
		std::string temp;
		std::stringstream buffer;
		buffer << i;
		buffer >> temp;
		if( isPalindrome(temp) && isPalindrome( binary(temp) ) ) {sum += i;}
	}
	std::cout<< sum << std::endl;
	return 0;
}	