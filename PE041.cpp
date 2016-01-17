#include <string>
#include <iostream>
#include <cmath>
void mergesort(std::string& sort, int low, int high){
	if (low >= high - 1) return;
	int mid = (low + high)/2;
	mergesort(sort, low, mid);
	mergesort(sort, mid, high);
	int l1 = low, h1 = mid, l2 = mid, h2 = high;
	std::string temp;
	while( l1 < h1 && l2 < h2 ){
		if(sort[l1] < sort[l2])	temp += sort[l1++];
		else	temp += sort[l2++];
	}
	while ( l1 < h1 )	temp += sort[l1++];
	while ( l2 < h2 )	temp += sort[l2++];
	for(int i = 0; i < temp.size(); i++)		sort[i + low] = temp[i];
}
bool isPandigital(std::string n){
	mergesort(n,0,n.length());
    for(int i = 0; i < n.length(); i++)
        if( i+1 != n[i] - '0') return false;
    return true;
}
bool isPrime(long long n){
	if( n == 2)		return true;
	if( n == 1 || n % 2 == 0)	return false;
	for( int i = 3; i <= sqrt(n) + 1; i += 2)
		if(n % i == 0)	return false;
	return true;
}
int main(){
	int result = 0;
	for(long long i = 2134; i < 987654321; i++){
		if( isPrime(i) )
			if( isPandigital( std::to_string(i) ) )	result = i;
	}	
	std::cout<< result <<std::endl;
	return 0;
}