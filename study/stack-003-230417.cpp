//�д翡 �ٶ��� �д�

//3*3������ ���� 1ĭ���� �������� ���� �����۹��� �ɾ��� ����
//��ǳ�� �Ҹ�, �ֻ�� �۹��� ��ǰ�� ���⸸ŭ �������� ���� (������ �����)
//�Է� : ��ǥ�� N, (y��ǥ, x��ǥ, �۹��� ��������), ��ǳȽ�� K, ��ǳ�� ����
//��� : ���� �۹��� ����

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, K;
	vector<int> board[3][3];

	int y, x;
	string powers;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> y >> x >> powers;
		for (int j = 0; j < powers.length(); j++) {
			board[y][x].push_back(powers[j] - '0');
		}
	}

	cin >> K;
	int wind;
	int cnt = 0;

	for (int n = 0; n < K; n++) {
		cin >> wind;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int bs = board[i][j].size();
				if (bs == 0)continue;

				board[i][j][bs - 1] -= wind;
				if (board[i][j][bs - 1] <= 0) board[i][j].pop_back();

				if (n == K - 1)cnt += board[i][j].size();
			}
		}
	}

	cout << cnt;
}