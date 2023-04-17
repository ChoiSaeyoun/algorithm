//���ο� ȸ������ �ý���

//�̸� ��Ģ�� �°� �����ϱ�
//1. ù���� �빮��, ������ �ҹ��� -> �״��
//2. ��� �ҹ��� -> ù���ڸ� �빮�ڷ�
//3. ��ҹ��� �������� -> ��� �빮�ڷ�

//�Է� : N��, N���� �̸�
//��� : �̸� ��Ģ�� �°� ����� �̸��� ���� ������ ����

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int checkFirst(string input) {
	if (input[0] >= 'A' && input[0] <= 'Z')return 1;
	return 0;
}

int checkOthers(string input) {
	for (int i = 1; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') return 0;
	}
	return 1;
}

string changeName(string input) {
	string result = input;
	int a = checkFirst(input);
	int b = checkOthers(input);

	if (a && b) return result;
	if (!a && b) {
		result[0] -= 32; return result;
	}
	for (int i = 0; i < input.size(); i++) {
		if (!(input[i] >= 'A' && input[i] <= 'Z'))result[i] -= 32;
	}
	return result;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<string> names;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> name;
		names.push_back(changeName(name));
	}

	sort(names.begin(), names.end());
	for (auto i = names.begin(); i != names.end(); i++) {
		cout << *i << "\n";
	}
}