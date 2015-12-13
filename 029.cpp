#include <iostream>
#include <vector>
#include <cmath>
bool isDistinct(double value, std::vector<double> vec){
	for ( int i = 0; i < vec.size(); i++ ){
		if (value == vec[i])	return false;
	}
	return true;
}
int main(){
	std::vector<double> vec;
	for  (int i = 2; i < 101; i++){
		for ( int j = 2; j < 101; j++){
			if( isDistinct(pow(i,j),vec) )
				vec.push_back(pow(i,j));
		}
	}
	std::cout<< vec.size() <<std::endl;
	return 0;
}
