
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, prize;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		prize = 10000 + a * 1000;
	}
	else if (a == b) {
		prize = 1000 + a * 100;
	}
	else if (b == c) {
		prize = 1000 + b * 100;
	}
	else if (a == c) {
		prize = 1000 + a * 100;
	}
	else {
		prize = max({ a,b,c }) * 100;
	}
	cout << prize;
	
	return 0;
}
