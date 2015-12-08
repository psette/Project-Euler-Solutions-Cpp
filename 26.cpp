#include <iostream>
#include <vector>
bool isinvec(std::vector<int> vals, int n){
	for(int i = 0; i < vals.size(); i++){
		if(n == vals[i])	return true;
	}
	return false;
}
int isrecurr(int n){
	std::vector <int> vals;
	int curr = 1, count = 0;
	while(curr % n != 0){
		curr = curr % n * 10;
		count++;
		if(isinvec(vals, curr)) return count;
		else	vals.push_back(curr);
	}
	return -1;
}
int main(){
	int d = 0, max = 0;
	for(int i = 1; i < 1000; i++){
		if(isrecurr(i) > max){
			max = isrecurr(i);
			d = i;
		}
	}
	std::cout<< d <<std::endl;
}