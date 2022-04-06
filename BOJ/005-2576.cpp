#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input, min=100, sum=0;
	for (int i = 0; i < 7; i++) {
		cin >> input;
		if (input % 2 == 1) {
			sum += input;
			if (input < min)min = input;
		}
	}
	if (sum == 0) {
		cout << "-1";
		return 0;
	}
	cout << sum << "\n"<< min;
	return 0;
}
