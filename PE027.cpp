#include <iostream>
#include <cmath>
int maxcount;
bool isPrime (int n){
    if (n <= 1)	return false;
    if (n == 2)	return true;
    if (n % 2 == 0)	return false;
    for (int i = 3; i < (int)(sqrt(n)) + 1; i += 2){
        if (n % i == 0)	return false;
    }
    return true;   
}
bool moreprimenums(int a, int b){
	int n = 0;
	while  isPrime( pow( n,2 ) + a * n + b ) )	n++;
	if (n > maxcount){
		maxcount = n;
		return true;
	}
	return false;
}
int main(){
	int product = 0;
	for (int a = -1000; a < 1001; a++){
		for (int b = -1000; b < 1001; b++){
			if (moreprimenums(a,b))	product = a * b;
		}
	}
	std::cout<< product << std::endl;
	return 0;
}