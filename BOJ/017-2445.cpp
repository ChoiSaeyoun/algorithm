#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int j = 1;
		for (; j <= i; j++)cout << "*";
		for (; j <= 2 * N - i; j++)cout << " ";
		for (; j <= 2*N; j++)cout << "*";
		cout << "\n";
	}
	for (int i = N-1; i >=1; i--) {
		int j = 1;
		for (; j <= i; j++)cout << "*";
		for (; j <= 2 * N - i; j++)cout << " ";
		for (; j <= 2 * N; j++)cout << "*";
		cout << "\n";
	}
	

	return 0;
}
