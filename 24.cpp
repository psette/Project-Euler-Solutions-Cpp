#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> result;
void mergesort(std::vector<std::string>& input, int low, int high) {
    if (low >= high - 1)
    	return;

	int mid = (low + high) / 2;
    mergesort(input, low, mid);
    mergesort(input, mid, high);
	int l1 = low;
	int h1 = mid;
	int l2 = mid;
	int h2 = high;

	std::vector<std::string> temp;
    while (l1 < h1 && l2 < h2)
    	if (input[l1] < input[l2])
			temp.push_back(input[l1++]);
		else
			temp.push_back(input[l2++]);

    while (l1 < h1)
    	temp.push_back(input[l1++]);

    while (l2 < h2)
    	temp.push_back(input[l2++]);

    for (int i = 0; i < temp.size(); ++i)
    	input[i + low] = temp[i];
}
void permute(std::string input, int i = 0){
	if(i == input.size() - 1)
		result.push_back(input);
	else{
		for( int j = i; j < input.size(); j++){
			std::swap(input[i],input[j]);
			permute(input,i+1);
			std::swap(input[i],input[j]);
		}
	}		
}
int main(){
	permute("0123456789");
	mergesort(result,0,result.size());
	std::cout<<result[999999]<<endl;
	return 0;
}