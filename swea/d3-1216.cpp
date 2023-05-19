#include<iostream>
#include<string>
using namespace std;

const int n = 100;
string map[n];
string s1, s2, s;

bool isValid(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i])return false;
	}
	return true;
}
string getColumn(int y, int x, int len) {
	s = "";
	for (int i = y; i < y + len; i++) {
		s += map[i][x];
	}
	return s;
}
int maxLen() {
	for (int len = n; len >= 1; len--) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x <= n - len; x++) {
				s1 = map[y].substr(x, len);
				s2 = getColumn(x, y, len);
				if (isValid(s1) || isValid(s2))return len;
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case;
		for (int i = 0; i < n; i++)cin >> map[i];
		cout << "#" << test_case << " " << maxLen() << "\n";
	}
	return 0;
}