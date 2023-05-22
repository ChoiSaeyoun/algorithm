//level 44-3
//SOS 모스부호

#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

string mos[5] = {
	"1011",
	"0011",
	"1111",
	"0000",
	"1100"
};
unordered_map<string, int>m;
string input[5];
string subInput;

int isMos() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= input[i].length() - 4; j++) {
			subInput = input[i].substr(j, 4);
			if (m[subInput] == 1) {
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) {
		m[mos[i]] = 1;
	}
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}
	if (isMos())cout << "yes";
	else cout << "no";

	return 0;
}