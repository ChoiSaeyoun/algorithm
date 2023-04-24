//LEVEL 34-1
//Binary Search

#include <iostream>
using namespace std;

int arr[10] = { 4,4,5,7,8,10,20,22,23,24 };

int bs(int start, int end, int target) {
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == arr[mid])return 1;
		if (target < arr[mid])end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}
int main() {
	int x;
	cin >> x;

	if (bs(0, 10, x))cout << "O";
	else cout << "X";
}