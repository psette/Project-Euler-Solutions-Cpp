#include <iostream>  
#include <math.h>  
bool is_Prime(int n){  
        for(int i=3; i<=sqrt(n); i+=2){
              if(n % i == 0)  return false;
        }
        return true;  
}  
  
int main()  {  
        int n = 3;  
        int max = 10001;  
        for(int i = 1; i != max; n++)  {
                if(n % 2 == 1 && is_Prime(n))  i += 1;  
                if(i == max)    break; 
        }  
  
        std::cout << n <<std::endl;  
        return 0;  
}  
