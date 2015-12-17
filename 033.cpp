#include <iostream>
int gcd(int num, int denom) {
    return denom == 0 ? num : gcd(denom, num % denom);
}
bool isDigitCancel(int num, int denom){
	if(num % 10 == 0 && denom % 10 == 0)	return false;
	int num_parts[2] = {num % 10, num / 10} , denom_parts[2] = {denom % 10, denom / 10};
	if( num_parts[0] == denom_parts[0])
		if(1.0 * num_parts[1] / denom_parts[1] == 1.0 * num / denom)	return true;
	if( num_parts[0] == denom_parts[1])
		if(1.0 * num_parts[1] / denom_parts[0] == 1.0 * num / denom)	return true;
	if( num_parts[1] == denom_parts[0])
		if(1.0 * num_parts[0] / denom_parts[1] == 1.0 * num / denom)	return true;
	if( num_parts[1] == denom_parts[1])
		if(1.0 * num_parts[0] / denom_parts[0] == 1.0 * num / denom)	return true;
	return false;
}
int main(){
	int result_num = 1, result_denom = 1;
	for (int denom = 11; denom < 100; denom++){
		for (int numerator = 10; numerator < denom; numerator++){
			if( isDigitCancel(numerator, denom) ){ 
				result_denom *= denom;
				result_num *= numerator;
			}
		}
	}
	std::cout<< result_denom / gcd(result_num, result_denom) <<std::endl;
	return 0;
}