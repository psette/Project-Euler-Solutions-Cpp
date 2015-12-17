#include <iostream>
int fact(int num){
	if( num == 0) return 1;
    int result = num;
    for (int i = 1; i < num; i++)
        result *= i;
    return result;
}
bool digitsFact(int num){
	int sum = 0, goal = num;
	while(num > 0){
		int temp = num % 10;
		num /= 10;
		sum += fact(temp);
		if(sum > goal) return false;
	}
	return (sum == goal);
}
int main(){
	int result = 0;
	for(int i = 3; i < 99999 ;i++)
        if (digitsFact(i))	result += i;
	std::cout<< result <<std::endl;
	return 0;
}