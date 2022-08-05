#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int arr[100000] = { 0 };
	int brr[2000000] = { 0 };
	int x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		brr[arr[i]] = 1;
	}
	cin >> x;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if(x - arr[i] == arr[i])continue;
		if (brr[x - arr[i]] == 1)cnt++;
		cout << i;
	}
	cout << cnt/2;
	return 0;
}
