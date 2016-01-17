#include <iostream>
int isDivisible(int num){
   bool result = true;
   for(int i = 1;i <= 20;i++){
      if(num % i != 0){
         result = false;
         break;
      }
   }
   if(!result) isDivisible(num+1);
   else  std::cout<<num<<std::endl;
   return num;
}
int main(){
   isDivisible(1);
   return 0;
}
