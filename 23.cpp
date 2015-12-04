#include <iostream>
#include <vector>
bool abundant(int n){
	int sum = 0;
	for(int i = 1; i < n; i++){
		if(n%i == 0)
			sum += i;
	}
	if(sum > n)	return true;
	return false;
}
std::vector<int> abundantnums(std::vector<bool>& allnumbers){
	std::vector<int> result;
	for(unsigned int i = 1; i < 28124; i++){
		allnumbers.push_back(false);
		if(abundant(i))	result.push_back(i);
	}
	return result;	
}
std::vector<bool> sumofabundant(std::vector<bool>& result){
	std::vector<int> vector = abundantnums(result);
   	for(unsigned a = 0; a < vector.size(); a++){
	    for(unsigned b = 0; b < vector.size(); b++){
	        if(vector[a]+vector[b] < 28124)	result[vector[a]+vector[b]] = true;
	    	else	break;     
	    }
	}
	return result;
}
int main(){
	int result = 0;
	std::vector<bool> numbers;
	sumofabundant(numbers);
	for(unsigned int i = 1; i < 28124; i++){
		if(!numbers[i])
			result += i;
	}
	std::cout<<result<<std::endl;
	return 0;
}