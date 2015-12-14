#include <iostream>
#include <vector>
#include <cmath>
bool isSum(int n, std::vector<int> powvec){
	std::vector<int> digits;
	int temp = n, sum = 0;
	while ( temp != 0){
		digits.push_back( temp % 10);
		temp /= 10;
	}
	for (int i  = 0; i < digits.size(); i++){
		sum += powvec[digits[i]];
	}
	return (sum == n);
}
std::vector<int> initializer(){
	std::vector<int> result;
	for(int i = 0; i < 10; i++){
		result.push_back(pow(i,5));
	}
	return result;
}
int main(){
	int sum = 0, i = 2;
	std::vector<int> powvec = initializer();
	while (true){
		if (isSum( i, powvec )) sum += i;
		i++;
		std::cout<<sum<<std::endl;	
	}
	return 0;
}