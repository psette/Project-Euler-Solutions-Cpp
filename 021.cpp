#include <iostream>
int divisor(int n);
int main(){
	bool visited[10000];
	int sum=0;

	for (int i=1;i<10000;i++) {
		int result = divisor(i), result2 = (divisor(result1));
		if (result2 == i && result1 != result2){
			sum += i;
		}
	}
	std::cout<< sum <<std::endl;
	return 0;
}
int divisor(int n){
	int result=0;
	for (int i = 1; i < n; i++){
		if (n % i == 0){
			result += i;
		}
	}
	return result;
}