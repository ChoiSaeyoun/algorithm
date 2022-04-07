#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, a,b;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b<<'\n';
	}

	return 0;
}
