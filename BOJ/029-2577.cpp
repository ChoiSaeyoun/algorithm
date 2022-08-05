#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	int bucket[10] = { 0 };

	int sum = A * B * C;
	int a = 10, b=1;
	for (int i = 0; i < 9; i++) {
		if (sum < b)break;
		int x = (sum % a)/b;
		bucket[x]++;
		a *= 10;
		b *= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << bucket[i] << "\n";
	}

	return 0;
}
