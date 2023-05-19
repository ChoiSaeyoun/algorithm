//level 43-6
//첩보 작전 임무 결과

#include <iostream>
#include <unordered_map>
using namespace std;

char code[8] = "BTSGODZ";
int killCnt[7] = { 10,15,12,15,14,13,16 };
unordered_map<char, int>m;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 7; i++) {
		m[code[i]] = killCnt[i];
	}

	char input;
	cin >> input;
	cout << m[input];
	return 0;
}