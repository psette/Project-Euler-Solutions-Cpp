#include <iostream>
#include <vector>
#include <cmath>
bool helper( long num){
	return ( sqrt( num / 2 ) == int( sqrt ( num / 2 ) ) );
}
void init(std::vector<int>& prime_nums){
    prime_nums.push_back(2);
    for(int i = 3; i < 4500; i++){
        bool prime = true;
        for(int j = 0; j < prime_nums.size(); j++){
        	if( prime_nums[j] * prime_nums[j] > i) break;
            if(i % prime_nums[j] == 0){
                prime = false;
                break;
            }
        }
        if(prime) prime_nums.push_back(i);
    }
    return;
}
int main(){
 	std::vector<int> prime_nums;
 	init(prime_nums);
 	int result = 33;
	bool found = false;
	while( !found ){
	    int j = 0;
	    found = true;
	    result += 2;
	    while (result >= prime_nums[j]) {
	        if( helper(result - prime_nums[j]) ){
	            found = false;
	            break;
	        }
	        j++;
	    }
	}
	std::cout<< result <<std::endl;
}