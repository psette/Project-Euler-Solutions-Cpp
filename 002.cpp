#include <iostream>
int main(){
	long fib1 = 1, fib2 = 1, result = 0, summed = 0;
	while (result < 4000000) {
	    if ( result % 2 == 0 )	summed += result;
	    result = fib1 + fib2;
	    fib2 = fib1;
	    fib1 = result;
	}
	std::cout<< summed <<std::endl;
	return 0;
}
