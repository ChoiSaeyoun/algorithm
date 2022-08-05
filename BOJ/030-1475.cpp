#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;
	int bucket[10] = { 0 };
	int a = 10, b = 1;
	for (int i = 0; i < 10; i++) {
		if (b > x)break;
		int k = (x % a) / b;
		bucket[k]++;
		a *= 10;
		b *= 10;
	}
	bucket[6]=(bucket[6] + bucket[9]+1) / 2;
	bucket[9] = 0;
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (max < bucket[i])max = bucket[i];
	}
	cout << max;

	return 0;
}
