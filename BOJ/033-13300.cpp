#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, S, Y;
	int arr[2][6] = {};
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		arr[S][Y-1]++;
	}
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			cnt += ceil(double(arr[i][j]) / K);
		}
	}
	cout << cnt;
}
