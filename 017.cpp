#include <iostream>
int main(){
    int count = 0;
    for(int h = 0;h < 10; h++){
        for(int t = 0;t < 10; t++){
            for(int o = 0;o < 10; o++){
                if(h == 1||h == 2||h == 6){
                    (t+o == 0)?count += 10:count += 13;
                }
                if(h == 4||h == 5||h == 9){
                    (t+o == 0)?count += 11:count += 14;
                }
                if(h == 3||h == 7||h == 8){
                    (t+o == 0)?count += 12:count += 15;
                }
                if(t == 1){
                    if(o == 0){
                        count += 3;
                    }
                    if(o == 1||o == 2){
                        count += 6;
                    }
                    if(o == 3||o == 4||o == 8||o == 9){
                        count += 8;
                    }
                    if(o == 5||o == 6){
                        count += 7;
                    }
                    if(o == 7){
                        count += 9;
                    }
                }
                if(t != 1){
                    if(t == 2||t == 3||t == 8||t == 9){
                        count += 6;
                    }
                    if(t == 4||t == 5||t == 6){
                        count += 5;
                    }
                    if(t == 7){
                        count += 7;
                    }
                    if(o == 1||o == 2||o == 6){
                        count += 3;
                    }
                    if(o == 4||o == 5||o == 9){
                        count += 4;
                    }
                    if(o == 3||o == 7||o == 8){
                        count += 5;
                    }
                }
            }
        }
    }
    std::cout<< count + 11 <<std::endl;
    return 0;
}