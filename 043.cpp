#include <iostream>
#include <string>
#include <vector>
void permute(std::string input,std::vector<std::string>& nums, int i = 0){
	if(i == input.size() - 1)	nums.push_back(input);
	else{
		for( int j = i; j < input.size(); j++){
			std::swap(input[i],input[j]);
			permute(input, nums , i + 1);
			std::swap(input[i],input[j]);
		}
	}		
}
bool isSub(std::string s){
	int a = atoi( ( s.substr(1,3).c_str() ) ), b = atoi( ( s.substr(2,3).c_str() ) );
	int c = atoi( ( s.substr(3,3).c_str() ) ), d = atoi( ( s.substr(4,3).c_str() ) );
	int e = atoi( ( s.substr(5,3).c_str() ) ), f = atoi( ( s.substr(6,3).c_str() ) ), g = atoi( ( s.substr(7,3).c_str() ) );
	return (a % 2 == 0 && b % 3 == 0 && c % 5 == 0 && d % 7 == 0 && e % 11 == 0 && f % 13 == 0 && g % 17 == 0);
}
int main(){
	long result = 0;
	std::vector<std::string> nums;
	permute("0123456789", nums);
	for(int i = 0; i < nums.size(); i++)
		if( isSub( nums[ i ] ) ) 	result += atol(nums[i].c_str()); 
	std::cout<< result <<std::endl;
	return 0;
}
