//���ĺ� ī�� ����

//�Է� : �빮�� ���ĺ� ���ڿ�, ���� ī�� �� N
//��� : ���ڿ��� ���������� �������� ��, ���� �ڿ� �ִ� N���� ī�� �� �󵵼��� ���� ����
//(�����̶��, ������ �տ� �ִ� ����)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;
	string tar;
	int N;
	int dat[200] = {};
	int maxI = 0;

	cin >> str >> N;

	sort(str.begin(), str.end());
	tar = str.substr(str.length() - N + 1, N);

	for (int i = 0; i < tar.length(); i++) {
		dat[tar[i]]++;
		if (dat[tar[i]] > dat[tar[maxI]])maxI = i;
	}

	cout << tar[maxI];
}