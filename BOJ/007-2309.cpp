#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[9],sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
		if (arr[i] == 0)break;
	}
	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++)cout << arr[i] << "\n";
	return 0;
}
