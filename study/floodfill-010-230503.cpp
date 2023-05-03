//�Է� : ������(1), ������(2), ��(-1), ����(0), ������(0/1/2/3) �ϵ��ڵ�
//��� : [����/����/�ð���� 90�� ȸ��/�ݽð���� 90�� ȸ��] 
//       �������� ��ǥ����, ��ǥ������� ���� �ּ� ���� Ƚ��

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int dir, y, x, level;
};
queue<Node>q;
Node start = { 1, 0,0,0 };
Node target = { 2, 0,3,0 };
int map[3][4] = {
	0,0,-1,0,
	-1,0,-1,0,
	0,0,0,0
};
int used[4][3][4];
void push(int dir, int y, int x, int level) {
	if (dir == -1)dir = 3;
	if (dir == 4)dir = 0;

	if (y < 0 || x < 0 || y >= 3 || x >= 4)return;
	if (map[y][x] == -1)return;
	if (used[dir][y][x] == 1)return;

	used[dir][y][x] = 1;
	q.push({ dir,y,x,level });
}
int bfs() {
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.y == target.y && now.x == target.x && now.dir == target.dir)return now.level;
		if (now.dir == 1 || now.dir == 3) {
			push(now.dir, now.y, now.x - 1, now.level + 1);
			push(now.dir, now.y, now.x + 1, now.level + 1);
		}
		else {
			push(now.dir, now.y - 1, now.x, now.level + 1);
			push(now.dir, now.y + 1, now.x, now.level + 1);
		}
		push(now.dir + 1, now.y, now.x, now.level + 1);
		push(now.dir - 1, now.y, now.x, now.level + 1);
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	q.push({ start.dir,start.y,start.x,0 });
	used[start.dir][start.y][start.x] = 1;

	cout << bfs();
	int a = 1;
	return 0;
}