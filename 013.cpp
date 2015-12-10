#include <iostream> 
#include <string>
int main ()
{	
	int result[50];
	int car = 0;
	std::string numbers[100];
	for(int i =0;i<100;i++){
		std::cin>>numbers[i];
	}
 	for(int i=0;i<50;i++){
 		result[49-i]=car;
 		for(int j=0;j<100;j++){
 			result[49-i]+= (int)numbers[j].at(50-i);
 		}
 		car=result[49-i]/10;
 	}
	for (int i=0; i<50; i++){
		std::cout <<result[i]%10<<std::endl;
	}	
	return 0;
}