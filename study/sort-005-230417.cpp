//Bit ���� ��ȣ ��õ ���α׷�

//�Է� : ������ N�� ��, N*N���� 0~9������ ��ȣ(��ȣ��), N*N���� 0 �Ǵ� 1(��Ʈ�迭)
//��� : ��Ʈ�迭�� 1�� �ش��ϴ� ��ġ�� ��ȣ���� ��ȣ�� �켱������ �°� ����
//(�켱���� : 1. �󵵼��� ���� �� 2. ���ڰ� ���� ��

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dat[20] = {};

int compare(int a, int b) {
	if (dat[a] > dat[b])return 1;
	if (dat[a] < dat[b])return 0;

	return a < b;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<vector<int>> nb(N);
	vector<int> result;
	int num, bit;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			nb[i].push_back(num);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bit;
			if (bit) {
				int tar = nb[i][j];
				result.push_back(tar);
				dat[tar]++;
			}
		}
	}

	sort(result.begin(), result.end(), compare);

	for (auto i = result.begin(); i != result.end(); i++)cout << *i << " ";
}