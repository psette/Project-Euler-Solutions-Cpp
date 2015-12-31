#include <iostream>
#include <cmath>
bool isPentagonal(int num){
    return ( (sqrt(1 + 24 * num) + 1.0) / 6.0  == int( (sqrt(1 + 24 * num) + 1.0) / 6.0 ) ) ; 
}
int main(){
	int i = 2;
	bool found = false;
	while(!found){
		int temp_i = 0.5 * (3 * i * i - i);
		for( int j = i  -  1; j > 0; j--){
			int temp_j = 0.5 * (3 * j * j - j);
			if( isPentagonal( temp_i + temp_j) && isPentagonal( temp_i - temp_j ) ){
				std::cout<< temp_i - temp_j <<std::endl;
				found = true;
				break;
			}
		}
		i++;
	}
	return 0;
}
