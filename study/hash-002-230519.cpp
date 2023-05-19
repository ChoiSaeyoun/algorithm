//level 43-1
//A-F 원소 정리

#include <iostream>
#include<unordered_map>
using namespace std;

unordered_map<char, int>m;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z')m[input[i] - 32]++;
		else m[input[i]]++;
	}

	for (char c = 'A'; c <= 'F'; c++) {
		cout << c << ":" << m[c] << "\n";
	}

	int a = 1;
	return 0;
}