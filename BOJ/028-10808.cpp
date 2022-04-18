#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[100] = { 0, };
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		arr[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
