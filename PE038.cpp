#include <iostream>
#include <string>
#include <cmath>
#include <vector>
void mergesort(std::string& sort, int low = 0, int high = 9){
	if (low >= high - 1) return;
	int mid = (low + high)/2;
	mergesort(sort, low, mid);
	mergesort(sort, mid, high);
	int l1 = low, h1 = mid, l2 = mid, h2 = high;
	std::string temp;
	while( l1 < h1 && l2 < h2 ){
		if(sort[l1] < sort[l2])
			temp += sort[l1++];
		else
			temp += sort[l2++];
	}
	while ( l1 < h1 )
		temp += sort[l1++];
	while ( l2 < h2 )
		temp += sort[l2++];
	for(int i = 0; i < temp.size(); i++)
		sort[i + low] = temp[i];
}
bool isPandigital(std::string n){
    if(n.length() < 9) return false;
    mergesort(n);
    for(int i = 0; i < 9; i++)
        if( i+1 != n[i] - '0') return false;
    return true;
}
int main(){
	std::string result;
	for(int i = 1; i < 10000 ; i++){
		std::string num = std::to_string(i);
		int j = 2;
		while( num.length() < 9){
			num += std::to_string(i * j++);
		}
		if( isPandigital(num) )
			if(num > result)	result = num;
	}	
	std::cout<< result <<std::endl;
	return 0;
}