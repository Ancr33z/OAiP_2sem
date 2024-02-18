#include <iostream>
using namespace std;
int as(int i, ...);
void main() {
	cout << as(5, 1, 2, 3, 4, 5) << endl;
	cout << as(7, 8, 7, 6, 5, 4, 3, 2) << endl;
	cout << as(9, 5, 3, 7, 1, 9, 5, 4, 2, 3);
}
int as(int i, ...) {
	int sum = 0;
	int* ptr = &i + 2;
	for (int j = 0; j < i - 1; j++) {
		if (j % 2 == 0)
			sum += *ptr * (*(ptr + 2));
		else
			sum -= *ptr * (*(ptr + 2));
		ptr = ptr + 2;
	}
	return sum;
}
//1*2-2*3+3*4-4*=-12
// 8*7-7*6+6*5-5*4+4*3-3*2=30
//5*3-3*7+7*3-3*9+9*5-5*4+5*4-4*2+2*3