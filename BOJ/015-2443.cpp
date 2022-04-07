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
		for (int j = 1; j < i; j++)cout << " ";
		for (int j = 0; j < (2 * N + 1) - 2 * i; j++) cout << "*";
		cout << "\n";
	}

	return 0;
}
