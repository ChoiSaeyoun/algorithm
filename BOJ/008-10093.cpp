#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, temp;
	cin >> A >> B;

	if (A > B) {
		temp = A;
		A = B;
		B = temp;
	}
	if (A == B) {
		cout << "0\n";
		return 0;
	}

	cout << B - A - 1 << "\n";
	for (long long i = A + 1; i < B; i++)cout << i << " ";

	return 0;
}
