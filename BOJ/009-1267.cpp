#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, a=0, b=0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> M;
		a += (M / 30+1)*10;
		b += (M / 60 + 1) * 15;
	}

	if (a < b)cout << "Y " << a;
	else if (a > b) cout << "M " << b;
	else cout << "Y M " << a;

	return 0;
}
