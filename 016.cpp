#include <iostream>
#include <vector>
int main(){
	std::vector<int> bignum;
	bignum.push_back(2);
	int carry = 0, size = bignum.size(), result;
	for(int j = 1; j < 1000; j++){
		size = bignum.size();
		carry = 0;
		for(int i = 0;i<size;i++){
			if(bignum[i] * 2 + carry > 9){
				bignum[i] = bignum[i]*2+carry-10;
				carry = 1;
				if(i == size - 1){
					bignum.push_back(1);
				}
				continue;
			}
				bignum[i] = bignum[i] * 2 + carry;
				carry = 0;
		}
	}
	for(int i = bignum.size() - 1;i >= 0; i--){	
		result += bignum[i];
 	}
	std::cout<<result<<std::endl;
    return 0;
}
