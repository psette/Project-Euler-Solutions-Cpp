#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void merge(std::vector<std::string>& input, int low, int high, int mid);
void mergesort(std::vector<std::string>& input, int low, int high) {
    if (low >= high - 1)
    	return;
3
	int mid = (low + high) / 2;
    mergesort(input, low, mid);
    mergesort(input, mid, high);
    merge(input, low, high, mid);
}
void mergesort(std::vector<std::string>& input) {
	mergesort(input, 0, input.size());
}
void merge(std::vector<std::string>& input, int low, int high, int mid){
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

std::vector<std::string> read(){
	std::string temp;
	std::ifstream file ("names.txt");
	std::vector <std::string> names;
	unsigned int sum = 0;
	while ( getline( file , temp , ',' ) ){
		names.push_back(temp);
		temp = "";
	}
	return names;

}
int scorename(std::string input){
	int result=0;
	for ( int j = 1; j  < input.length()-1; j++){
		result += (int)input.at(j) - 64;
	}
	return result;
}
int scoretot(std::vector<std::string> names){
	int sum=0;
	for ( int i = 0; i < names.size(); i++ ){
		sum += (i+1)* scorename(names[i]);
	}
	return sum;
}
int main(){
	std::vector <std::string> names = read();
	mergesort(names);
	std::cout<< scoretot(names) <<std::endl;
	return 0;
} 
