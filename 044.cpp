#include <iostream>
#include <vector>
bool binsearch( std::vector<int> nums, int key, int low, int high){
	if(low > high)	return false;
	int mid = (low + high) / 2;
	if( nums[mid] > key) return binsearch(nums, key, low, mid - 1);
	if( nums[mid] < key) return binsearch(nums, key, mid + 1, high);
	if( nums[mid] == key) return true;
}
bool isPentagonal(int target, std::vector<int>& nums){
	while( target > nums[ nums.size() - 1 ])	nums.push_back ( 0.5 * (nums.size() * nums.size() + nums.size() ) );
	return binsearch( nums, target, 0, nums.size() ); 
}
int main(){
	int i = 0;
	std::vector<int> pentags;
	pentags.push_back(1);
while(true)
	for( int j = 0; j < i; j++){
		if( isPentagonal( pentags[i] + pentags[j] ) && isPentagonal( pentags[i] - pentags[j] ) && pentags[j] * pentags[j] - pentags[i][i] ){
				std::cout<<
		}
	}
	i++;
}
