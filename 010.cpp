#include <iostream>
#include <math.h>
bool is_Prime(int n)  
{  
        bool result = true;  
        for(int i=3; i<=sqrt(n); i+=2)  
        {  
                if(n % i == 0)  
                {  
                        result = false;  
                        break;  
                }  
        }  
        return result;  
}  
  
int main()  
{       long long sum=0;
        long max = 2000000;  
        for(int n=3; n <= max; n++)  
        {  
                if(n%2==1&&is_Prime(n))  
                {  
                        sum+=n;  
                }  
        }  
  
        std::cout << sum<<std::endl;  
        return 0;  
}  

