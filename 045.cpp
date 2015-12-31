#include <iostream>
#include <cmath>
bool isPentagonal(long num){
    return ( (sqrt(1 + 24 * num) + 1.0) / 6.0  == int( (sqrt(1 + 24 * num) + 1.0) / 6.0 ) ) ; 
}
int main(){
	int i = 143;
	while( true ){
		i++;
		long hex = 2 * i * i - i;
		if( isPentagonal( hex ) ) {
			std::cout<< hex <<std::endl;
			break;
		}
	}
	return 0;
}
