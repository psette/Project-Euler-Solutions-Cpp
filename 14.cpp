#include <iostream>
int main(){
	long maxnum=0;
	long max=0;
	for(unsigned long int i=2;i<=1000000;i++){
		int count=1;
		long number=i;
	    while(number!=1){
	        if(number%2==0){
	            number/=2;
	        }
	        else{number=3*number+1;                             
	        	count++;
	    	}
	    }
	    if(count>max){
	    	max=count;
	    	maxnum=i;
	    }
	}
	std::cout<<maxnum<<std::endl;
	return 0;
}