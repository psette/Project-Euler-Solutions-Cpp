#include <iostream>
int main(){
	int n[20][20];
	int large = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			std::cin>>n[i][j];
		}
	}
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 16; j++){
			if (n[j][i] * n[j+1][i] * n[j+2][i] * n[j+3][i] > large ){
				large = n[j][i] * n[j+1][i] * n[j+2][i] *n[j+3][i];
			}
			if ( n[i][j] * n[i][j+1] * n[i][j+2] * n[i][j+3] > large ){
				large = n[i][j] * n[i][j+1] * n[i][j+2] * n[i][j+3];
			}
		}
	}
	for(int i = 0; i < 16; i++){
		for(int j = 0; j< 16;j++){	
	        if(n[i][j] * n[i+1][j+1] * n[i+2][j+2] * n[i+3][j+3] > large){
	        	large = n[i][j]*n[i+1][j+1]*n[i+2][j+2]*n[i+3][j+3];
	        }
	        if(n[i+3][j] * n[i+2][j+1] * n[i+1][j+2] * n[i][j+3] > large){
	        	large = n[i+3][j] * n[i+2][j+1] * n[i+1][j+2] * n[i][j+3];
	        }
	     }
	}
	std::cout<<large<<std::endl;;
	return 0;
}


