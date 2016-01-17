#include <iostream>
#include <cmath>
int main(){
	int result = 0;
	for(int i = 2; i < 10001; i++){
	  for (int n = 2; n < 10001; n++) {
            int limit = (int)sqrt(n);                                
            if (limit * limit == n) continue;
            int period = 0, d = 1, m = 0, a = limit;
 		 	do{                
           	   m = d*a - m;                    
               d = (n - m * m) / d;
                a = (limit + m) / d;
                period++;
                }while(a != 2*limit);
                
            if (period % 2 == 1) result++;
        }
    }
    std::cout<<result<<std::endl;
    return 0;
}