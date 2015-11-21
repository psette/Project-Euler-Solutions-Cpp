#include <iostream>
#include <math.h>
int main(){
bool found = false;
int b=0,c=0;
for (int a = 1; a < 500; a++) {
    for (b = a; b < 500; b++) {
       c = 1000 - a - b;
 
        if (a * a + b * b == c * c) {
            found = true;
            break;
        }
    }
 
    if (found) {
    std::cout<<a*b*c;
        break;
    }
}
}
