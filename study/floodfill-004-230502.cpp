//level 37-3
//ÆøÁ×³îÀÌ

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node { int y, x; };
queue<Node>q;
int dir[8][2] = {
	-1,-1,-1,0,-1,1,
	0,-1,0,1,
	1,-1,1,0,1,1
};
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int map[4][5];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				q.push({ y,x });
			}
		}
	}

	int t = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 5)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			t = map[ny][nx];
			q.push({ ny,nx });
		}
	}
	cout << t - 1;
	return 0;
}
