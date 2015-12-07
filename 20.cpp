#include <iostream>
#include <vector>
#include <algorithm>
int main(){
	std::vector<int> bignum;
	bignum.push_back(1)
	int counter=1,carry=0,answer=0;
	std::vector<int> ones,tens,result;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int temp1=0,temp2=0,size=bignum.size();
			for(int k=0;k<size;k++){
				temp1=bignum[k]*j;
				temp2=bignum[k]*i;
				while(temp1!=0){
	    			ones.push_back(temp1%10); 
	    			temp1=i/10;
				}
				while(temp2!=0){
	    			tens.push_back(temp2%10); 
	    			 temp2=i/10;
				}
				ones.reverse();
				tens.reverse();
				tens.push_back(0);
				if(ones.size()>tens.size()){
					for(int i=0;i<ones.size;i++){
						(i<tens.size())?ones[i]+=tens[i]:ones[i]=ones[i];
					}
										
				}
				else{
					for(int i=0;i<tens.size;i++){
						(i<ones.size())?tens[i]+=ones[i]:tens[i]=tens[i];
					}
				}
			}
		}
	}
	std::cout<<result<<std::endl;
	return 0;
}

#include <iostream>
#include <vector>
int main(){
	std::vector<int> bignum;
	bignum.push_back(2);
	int carry=0, size=bignum.size(), result;
	for(int j=1;j<1000;j++){
		size=bignum.size();
		carry=0;
		for(int i=0;i<size;i++){
			if(bignum[i]*2+carry>9){
				bignum[i]=bignum[i]*2+carry-10;
				carry=1;
				if(i==size-1){
					bignum.push_back(1);
				}
				continue;
			}
				bignum[i]=bignum[i]*2+carry;
				carry=0;
		}
	}
	for(int i=bignum.size()-1;i>=0;i--){	
		result+=bignum[i];
 	}
	std::cout<<result<<std::endl;
}
