#include <iostream>
void mergesort(std::string& input, int low, int high){
	if (low >= high - 1) return;
	int mid = (low + high) / 2;
	mergesort(input, low, mid);
	mergesort(input, mid, high);
	int l1 = low, l2 = mid, h1 = mid, h2 = high;
	std::string temp;
	while( l1 < h1 && l2 < h2)	input[l1] < input[l2] ? temp += input[l1++] : temp += input[l2++];
	while( l1 < h1)	temp += input[l1++];
	while( l2 < h2) temp += input[l2++];
	for(int i = 0; i < temp.size(); i ++) input[i + low] = temp[i];
}
bool helper(int n){
	std::string one, two, three, four, five, six;
	one = std::to_string(n);
	six = std::to_string( 6 * n);
	if( one.length() != six.length())	return false;
	two = std::to_string( 2 * n);
	three = std::to_string( 3 * n);
	four = std::to_string( 4 * n);
	five = std::to_string( 5 * n);
	mergesort(one, 0, one.length());
	mergesort(two, 0, two.length());
	mergesort(three, 0, three.length());
	mergesort(four, 0, four.length());
	mergesort(five, 0, five.length());
	mergesort(six, 0, six.length());
	return (one == six && two == five && three == four && one == two && one == three);
}
int main(){
	int i = 125874;
	while( !helper(i++) );
	std::cout<< i - 1 <<std::endl;
	return 0;
}