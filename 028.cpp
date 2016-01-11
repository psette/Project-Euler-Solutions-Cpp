#include <iostream>
int main(){
	int diagsum = 0;
	for(int i = 1001; i > 1; i -= 2){
		int corner1 = i * i;
		int corner2 = corner1 - i + 1;
		int corner3 = corner2 - i + 1;
		int corner4 = corner3 - i + 1;
		diagsum += corner1 + corner2 + corner3 + corner4;
	}
	std::cout << diagsum + 1 <<std::endl;
	return 0;
}