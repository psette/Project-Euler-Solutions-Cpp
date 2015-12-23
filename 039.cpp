#include <iostream>
#include <cmath>
int main(){
	int max = 0, index = 0;
	for(int p = 3; p <= 1000; p++){
		int soultions = 0;
		for(int a = 1; a < p; a++){
			if(p*(p-2*a) % (2*(p-a)) == 0) soultions++;
		}
		if(soultions > max){
			max = soultions;
			index = p;
		}
	}
	std::cout<< index <<std::endl;
	return 0;
}