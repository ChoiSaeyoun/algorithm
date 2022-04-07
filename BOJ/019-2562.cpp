#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b=0,c;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		if (a > b) {
			b = a;
			c = i + 1;
		}
	}
	cout << b << "\n" << c;

	return 0;
}
