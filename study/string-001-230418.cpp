//���ڵ� �˻�����

//6���� �ܾ� �ϵ��ڵ�
//�Է� : �� ������ �˻��� (ex. ??B?)
//��� : �ش��ϴ� �ܾ��� ����

#include <iostream>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string arr[6] = { "ABCD","ABCE","AGEH","EIEI","FEQE","ABAD" };
	string input;
	int cnt = 0;

	cin >> input;

	for (int i = 0; i < 6; i++) {
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (input[j] != '?') {
				if (arr[i][j] != input[j]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)cnt++;
	}

	cout << cnt;
}