//창밖에 흐르는 알파벳

//입력 : 한 문자열 (최대 10글자)
//출력 : 각 문자가 1씩 감소하며 출력 (A보다 작아지면 '_'출력)

#include <iostream>
using namespace std;

int isAllLine(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '_')return 0;
	}
	return 1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string input;
	cin >> input;

	cout << input << "\n";
	while (!isAllLine(input)) {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '_')continue;
			else if (input[i] == 'A')input[i] = '_';
			else input[i]--;
		}
		cout << input << "\n";
	}
}