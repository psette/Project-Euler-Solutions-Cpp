#include <iostream> 
#include <cmath>
int main(){
	double length=0;
	int n = 1;
	while ( length < 999){
		n++;
		length =  n * log10( 0.5 + pow( 5, 0.5 ) / 2 ) - log10( 5 ) / 2;
	}
	std::cout<< n <<std::endl;
	return 0;
}