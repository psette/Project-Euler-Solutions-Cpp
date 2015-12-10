#include <iostream>
bool inbounds(int position, int i);
int findmax(int** vals, int position,int i);
int main(){
	int vals[15][15];
	int sum=0, place=0, maxfirst=0,x=14;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			std::cin>>vals[i][j];
		}
	}
	for(int i=0;i<15;i++){
		if(vals[14][i]>=maxfirst){
			place=i;
			maxfirst=vals[14][i];
		}		
	}
	for (int i=13;i>=0;i--) {
		for (int j=0;j<i+1;j++) {
			vals[i][j]+=std::max(vals[i+1][j],vals[i+1][j+1]);
		}
	}
	std::cout << vals[0][0] << std::endl;
}