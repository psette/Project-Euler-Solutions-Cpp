#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
std::vector<std::string> read(){
	std::string temp;
	std::ifstream file ("names.txt");
	std::vector <std::string> names;
	unsigned int sum = 0;
	while( getline( file , temp , ',' ) ){
		names.push_back(temp);
		temp = "";
	}
	return names;

}
int scorename(std::string input){
	int result=0;
	for( int j = 1; j  < input.length()-1; j++){
		result += (int)input.at(j) - 64;
	}
	return result;
}
int scoretot(std::vector<std::string> names){
	int sum=0;
	for( int i = 0; i < names.size(); i++ ){
		sum += (i+1)* scorename(names[i]);
	}
	return sum;
}

int main(){
	std::vector <std::string> names = read();
	std::sort(names.begin() , names.end());
	std::cout<<scoretot(names)<<std::endl;
	return 0;
}