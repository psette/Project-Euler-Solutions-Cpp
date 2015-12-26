#include <iostream>
#include <string>
#include <fstream>
#include <vector>
int scoreword(std::string input){
	int result=0;
	for ( int j = 1; j  < input.length()-1; j++)	result += (int)input.at(j) - 64;
	return result;
}
bool binsearch( std::vector<int> nums, int key, int low, int high){
	if(low > high)	return false;
	int mid = (low + high) / 2;
	if( nums[mid] > key) return binsearch(nums, key, low, mid - 1);
	if( nums[mid] < key) return binsearch(nums, key, mid + 1, high);
	if( nums[mid] == key) return true;
}
bool isTriangle(int score, std::vector<int>& nums){
	while( score > nums[ nums.size() - 1 ])	nums.push_back ( 0.5 * (nums.size() * nums.size() + nums.size() ) );
	return binsearch( nums, score, 0, nums.size() ); 
}
int main(){
	std::vector<int> triangle_nums;
	for(int i = 0; i < 20; i++)	triangle_nums.push_back( 0.5 * (i * i + i ) );
	std::string temp;
	std::ifstream file ("words.txt");
	unsigned int sum = 0;
	while ( getline( file , temp , ',' ) )	if( isTriangle( scoreword ( temp ) , triangle_nums ))	sum++;
	std::cout<< sum <<std::endl;
	return 0;
} 