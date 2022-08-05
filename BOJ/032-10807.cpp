#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arr[105] = { 0 };
	int v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> v;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == v)cnt++;
	}
	cout <<  cnt;
	return 0;
}
