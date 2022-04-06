#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, sum;
	for (int j = 0; j < 3; j++) {
		sum = 0;
		for (int i = 0; i < 4; i++) {
			cin >> a;
			sum += a;
		}
		if (sum == 0)cout << "D";
		if (sum == 1)cout << "C";
		if (sum == 2)cout << "B";
		if (sum == 3)cout << "A";
		if (sum == 4)cout << "E";
		cout << "\n";
	}

	return 0;
}
