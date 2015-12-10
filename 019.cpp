#include <iostream>
int main(){
	int sundays=0, months[12]={31,28,31,30,31,30,31,31,30,31,30,31}, days=1;
	for(int year=1901;year<=2000;year++){
		if(year%4==0){
			if(year%100==0&&year%400==0){
				months[1]=29;
			}
			if(year%100!=0){
				months[1]=29;
			}
		}
		else{
			months[1]=28;
		}
		for(int monthcount=0;monthcount<12;monthcount++){
			for(int dayofmonth=0;dayofmonth<months[monthcount];dayofmonth++){
				days++;
				if(days==7){
					days=0;
				}
				if(days==6&&dayofmonth==0){
					sundays++;
				}
			}
		}
	}
	std::cout<<sundays<<std::endl;
	return 0;
}