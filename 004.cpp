#include <iostream>
using namespace std;

bool isPalindrome(int num);
int main(){
int largest_palindrome = 0;;
for(int a = 100;a <= 999; a++){
   for(int b = 100;b <= 999; b++){
      int product = a*b;
      if(largest_palindrome < product && isPalindrome(product)){
       largest_palindrome = product;
      }
   }
}
cout<< largest_palindrome <<endl;
return 0;
}
bool isPalindrome(int num){
   int original_num = num;
   int reversed = 0;
   while(num>=1){
      reversed = reversed * 10 + num % 10;
      num = num / 10;
   }
   bool result = (original_num==reversed);
   return result;
}
