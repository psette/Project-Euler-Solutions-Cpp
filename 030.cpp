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
	for (int i  = 0; i < digits.size(); i++)
		sum += powvec[digits[i]];
	return (sum == n);
}
int main(){
	int sum = 0, i = 2, limit = pow(9,5) * 5;
	std::vector<int> powvec;
	for (int i = 0; i < 10; i++){
		powvec.push_back(pow(i,5));
	}
	while (i < limit){
		if (isSum( i, powvec )) sum += i;
		i++;
	}
	std::cout<<sum<<std::endl;	
	return 0;
}