//LEVEL 31-6
//버스 주차요금 저렴한 곳 찾기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int arr[9] = { 1,2,3,3,5,1,0,1,3 };
	int n;

	cin >> n;
	int sum = 0, min;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	min = sum;

	int limit = 9 - n;
	for (int i = 0; i <= limit; i++) {
		if (min > sum)min = sum;
		if (i == limit)break;
		sum += arr[i + n];
		sum -= arr[i];
	}

	cout << min;
	return 0;
}