#include <iostream> 
#include <string>
int main ()
{	
	int result[50];
	int car = 0;
	string numbers[100];
	for(int i =0;i<100;i++){
		std::cin>>numbers[i];
	}
 	for(int i=0;i<50;i++){
 		result[50-i]=car;
 		for(int j=0;j<100;j++){
 			result[50-i]+= (int)numbers[j].at[50-i];
 		}
 		car=result[50-i]/10;
 	}
	for (x = 0; x < 50; x++){
		std::cout <<result[i]%10<<std::endl;
	}	
	return 0;
}