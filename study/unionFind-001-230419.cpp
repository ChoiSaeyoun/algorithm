//�Է� : ���� ���� n, n���� ������ ��ǥ
//7
//1 1
//1 2
//2 3
//2 4
//3 2
//4 2
//2 2
// 
//��� : (�����¿찡 �´��� ���� �ϳ��� ������ ����) ��ǥ�� �Էµ� �������� ���� ���� 
//1 1 2 2 3 3 1

#include <iostream>
using namespace std;

int boss[10];
int map[10][10];
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};
int makeGroupCnt = 0;

int getBoss(int x) {
	if (boss[x] == 0)return x;
	int ret = getBoss(boss[x]);
	boss[x] = ret;
	return ret;
}
void setBoss(int a, int b) {
	int A = getBoss(a);
	int B = getBoss(b);
	if (A == B)return;
	boss[B] = A;
	makeGroupCnt++;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, x, y, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		map[y][x] = ++cnt;
		for (int j = 0; j < 4; j++) {
			int ny = y + dir[j][0];
			int nx = x + dir[j][1];
			if (ny < 0 || nx < 0 || ny>10 || ny>10)continue;
			if (map[ny][nx] == 0)continue;
			setBoss(map[ny][nx], map[y][x]);
		}
		cout << cnt - makeGroupCnt << " ";
	}
}