//LEVEL 34-5
//root °è»ê±â

#include <iostream>
#include <string>
using namespace std;

int root(int start, int end, int target) {
	int mid = 0, max = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == target)return mid;
		if (mid * mid > target)end = mid - 1;
		else {
			start = mid + 1;
			if (max < mid)max = mid;
		}
	}
	return max;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int n;
	cin >> n;

	cout << root(0, n, n);

	return 0;
}