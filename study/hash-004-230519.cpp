//level 43-3
//같은 단어 찾아내기

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int>m;
string s = "BOBOOBOBOBOBBM";
int n;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i <= s.length() - 3; i++) {
		m[s.substr(i, 3)]++;
	}

	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << m[input] << "\n";
	}

	return 0;
}