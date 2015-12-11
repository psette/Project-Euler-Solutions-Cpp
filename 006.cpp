#include <iostream>
using namespace std;
int main(){
	int sum_of_s = 0;
	int s_of_sum = 0;
	for(int i = 1;i <= 100;++i){
		sum_of_s += i * i;
		s_of_sum += i;  
	}
	s_of_sum = s_of_sum * s_of_sum;
	cout<< s_of_sum-sum_of_s <<endl;
	return 0;
}
