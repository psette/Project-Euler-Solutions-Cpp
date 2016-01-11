#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
bool isPrime(int num){
	int limit = sqrt(num);
	for(int i = 3; i < limit + 1; i += 2){
		if(num % i == 0)	return false;
	}
	return true;
}
void intializer(std::vector<bool>& Primes){
	for(int i = 0; i < 1000000; i++)
		Primes.push_back(i % 2 != 0 && isPrime(i));
}
bool isCircular(int num, std::vector<bool>& Primes){
	std::string temp;
	std::stringstream buffer;
	buffer << num;
	buffer >> temp;
	for(int i = 0; i < temp.size(); i++){
		int newnum = 0;
		buffer.clear(); buffer.str("");
		temp += temp[0];
		temp.erase(temp.begin());
		buffer << temp;
		buffer >> newnum;
		if(!Primes[newnum]) return false;
	}
	return true;
}
int main(){
	int count = 1;
	std::vector<bool> Primes;
	intializer(Primes);
	for(int i = 3; i < 1000000; i += 2)
		if(i % 2 != 0 && isCircular(i,Primes)){
			count++;
		}
	std::cout<< count <<std::endl;
}