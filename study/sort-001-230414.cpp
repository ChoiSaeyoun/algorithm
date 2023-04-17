//����ü ��������
// 
//���ڿ� ���ڰ� �� ���� n�� Set�� ����ü �迭�� �Է� (1 <= n <= 100)
//�Ʒ� �켱������ ���� �������ķ� ���� �� ���
//1. �� ���� ���� �켱
//2. �� ���� ���� �켱

#include <iostream>
#include <vector>
using namespace std;

struct Set {
	int num;
	int ch;
};

int compare(Set a, Set b) {
	if (a.num < b.num)return 1;
	if (a.num > b.num)return 0;

	if (a.ch < b.ch)return 1;
	return 0;
}

int main() {
	int n;
	vector<Set> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		char b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 1; j--) {
			if (!compare(arr[j - 1], arr[j])) {
				swap(arr[j - 1], arr[j]);
			}
			else break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i].num << " " << (char)arr[i].ch << "\n";
	}
}