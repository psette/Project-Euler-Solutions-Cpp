#include <iostream>
#include <string>
#include <cmath>
#include <vector>
void mergesort(std::string& sort, int low, int high){
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
    mergesort(n,0,9);
    for(int i = 0; i < 9; i++){
        if( i+1 != n[i] - '0') return false;
    }
    return true;
}
bool alreadyHappened(std::vector<int> result, int n){
	for(int i = 0; i < result.size(); i++){
		if( n == result[i])	return true;
	}
	return false;
}
int main(){
	int sum = 0;
	std::vector<int> result;
    for(int i = 1; i < 9999; i++){
        for(int j = 1; j < 9999; j++){
			int  product = i * j;
			std::string pandig = std::to_string(i) + std::to_string(j) + std::to_string(product);
			if(pandig.length() > 9) break;
			if(isPandigital(pandig) && !alreadyHappened(result, product)){
				sum += product;
				result.push_back(product);
			}
		}
	}
	std::cout<< sum <<std::endl;
	return 0;
}