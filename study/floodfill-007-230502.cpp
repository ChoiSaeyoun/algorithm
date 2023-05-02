//level 37-6
//고기가 좋아

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
queue<Node> q;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int map[4][6];

int bfs() {
	int cnt = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 6)continue;
			if (map[ny][nx] == 1)continue;
			if (map[ny][nx] == 2)cnt++;
			map[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	return cnt;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}
	q.push({ 0,0 });
	map[0][0] = 1;
	cout << bfs();


	return 0;
}
