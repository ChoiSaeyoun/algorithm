//����� â������

//�� 5���� line�� 0~9������ ��ȣ�� �Է�
//������ line 2���� �Է¹޾� �������� ����
//�� line �� ���� �Ʒ��� �ִ� ��ȣ 5�� ���

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;
int lineNum[2];

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 5; i++) {
		string input;
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < 2; i++)cin >> lineNum[i];

	for (int i = 0; i < 2; i++) {
		string target = arr[lineNum[i]];
		sort(target.begin(), target.end());
		arr[lineNum[i]] = target;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i][0] << " ";
	}

}