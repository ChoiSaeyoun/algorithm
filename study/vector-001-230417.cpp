//��ȸ�ǿ� ��ǥ

//m���� ���ε��� n(1<=n<=100)���� ��ȸ�ǿ����� ��ǥ
//m,n���� m���� ��ǥ��ȣ�� ���� �̸� ���� �Է�
//�缱�� (���� ���� ǥ ��ǥ & ������ ��� �ռ� ��ȣ) ��ȸ�ǿ��� ���� ���ε� �̸� ���

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int m, n;
	cin >> m >> n;
	vector<vector<string>> list(n);

	int inputN;
	string inputName;

	int max = 0;
	int maxI = 0;

	for (int i = 0; i < n; i++) {
		cin >> inputN >> inputName;
		list[inputN].push_back(inputName);
	}

	for (int i = 0; i < m; i++) {
		if (list[i].size() > max) {
			max = list[i].size();
			maxI = i;
		}
	}

	for (int i = 0; i < list[maxI].size(); i++) {
		cout << list[maxI][i] << " ";
	}
}