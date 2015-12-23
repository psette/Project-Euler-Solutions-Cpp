#include <iostream>
#include <cmath>
int main(){
	int result = 1, target = 100, counter = 1, number_in_seq = 1;;
	while(target <= 1000000){
		int digits = log10(counter), temp = counter++, temp_sub = 0, place = 0;
		number_in_seq += digits + 1;
		while(number_in_seq + digits >= target){
			if(number_in_seq + digits - temp_sub++ == target){
				target *= 10;
				result *=  temp % 10;
				break;
			}
			temp /= 10;	
		}
	}
	std::cout<< result <<std::endl;
	return 0;
}