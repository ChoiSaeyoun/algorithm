//입력 : 정수
//출력 : 정수의 제곱근값 (소수점 버림)

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int bs(int start, int end, int target) {
	int max = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target == mid * mid)return mid;
		if (target < mid * mid)end = mid - 1;
		else {
			start = mid + 1;
			if (mid > max)max = mid;
			//start의 직전 값(=mid) : target이 mid^2 보다는 큰 수이지만, mid가 제곱근의 가능성이 있으므로
		}
	}
	return max;
}
int main() {

	int target;
	cin >> target;

	cout << bs(0, 20, target);

	return 0;
}