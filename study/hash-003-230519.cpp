//level 43-2
//빠른 이름검색

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int>m;
string names[5] = { "POP","TOM","MC","JASON","KFC" };
int n;
string input;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 5; i++) {
		m[names[i]]++;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (m.count(input) == 1)cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}