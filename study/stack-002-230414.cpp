//������ź

//N�� ���� N���� ��ź ��ȣ�� �Է�
//�Էµ� ������� ��ź�� �״ٰ�, ���� ���� ��ź ���� 3���� ��� ����
//���� �����ִ� ��ź���� �������� �����Ͽ� ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> list;
vector<int> input;
int arr[100];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		input.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		list.push_back(input[i]);

		if (i <= 1)continue;
		int tail = list.size() - 1;
		if (list[tail] == list[tail - 1] && list[tail - 1] == list[tail - 2]) {
			list.pop_back();
			list.pop_back();
			list.pop_back();
		}
	}

	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

}