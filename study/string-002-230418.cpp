//â�ۿ� �帣�� ���ĺ�

//�Է� : �� ���ڿ� (�ִ� 10����)
//��� : �� ���ڰ� 1�� �����ϸ� ��� (A���� �۾����� '_'���)

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