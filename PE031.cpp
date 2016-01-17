#include <iostream>
int main(){
	int ways = 1;
	for (int onehundred = 0; onehundred < 201; onehundred += 100){
		
		for (int fifty = 0; fifty < 201; fifty += 50){
			if(fifty + onehundred > 200)	break;

			for (int twenty = 0; twenty < 201; twenty += 20){
				if(twenty + fifty + onehundred > 200)	break;
	
				for (int ten = 0; ten < 201; ten += 10){
					if( ten + twenty + fifty + onehundred > 200)	break;

					for (int five = 0; five < 201; five += 5){
						if( five + ten + twenty + fifty + onehundred > 200)	break;

						for (int two = 0; two < 201; two += 2){
							if( two + five + ten + twenty + fifty + onehundred > 200)	break;

							for (int one = 0; one < 201; one++){
								if( onehundred + fifty + twenty + ten + five + two + one == 200)	ways++;
								if(onehundred + fifty + twenty + ten + five + two + one > 200)		break;
							}
						}
					}
				}
			}
		}
	}
	std::cout<< ways <<std::endl;
	return 0;
}