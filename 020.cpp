#include <iostream>
int main(){
int temp = 0, carry = 0, num = 0, sum = 0, digits[ 175 ] = { 0 };
digits[0] = 1;
for(int i = 1; i < 100; i++) {
  carry = 0;
  for (int j = 0;j < 175; j++){
    temp = digits[j] * i + carry;
    carry = 0;
    if (temp > 9){
      num = temp % 10;
      carry = temp / 10;      
    }
    else	num = temp;
    digits[j] = num;
  }
}
for (int i = 175 ;i > 0;i--)	sum += digits[ i - 1 ];
std::cout<< sum <<std::endl;
return 0;
}