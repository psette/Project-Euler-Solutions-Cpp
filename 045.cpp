#include <string>
#include <iostream>
#include <stdlib.h>
int main(){
	std::string temp = "123456789";
	int x = atoi(temp.substr(3,2).c_str());
	std::cout<<x+1;
	return 0;
}