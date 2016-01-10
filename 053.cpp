#include <iostream>
int fac(int n) {
    return n < 2 ? 1 : n * fac(n - 1);
}
bool isncrbig(int n, int r) {
    int denom = fac(r);
    long rest = n;
    for (int i = 1 - r; i < 0; i++) {
        rest *= i + n;
        if (rest / denom > 1000000)		return true;
    }
    return false;
}
int main() {
    int r = 10, result = 0;
    for (int n = 23; n <= 100; n++) {
        while (isncrbig(n, r - 1))	r--;
        result += n - 2 * r  + 1;
    }
    std::cout << result <<std::endl;
    return 0;
}	