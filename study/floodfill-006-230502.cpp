//level 37-5
//BFS로 미로찾기

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node { int y, x, level; };
queue<Node>q;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
int map[4][4] = {
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};
int sy, sx, ey, ex;

int bfs() {
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)continue;
			if (map[ny][nx] == 1)continue;
			if (ny == ey && nx == ex)return now.level + 1;
			map[ny][nx] = 1;
			q.push({ ny,nx,now.level + 1 });
		}
	}
	return 0;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> sy >> sx >> ey >> ex;
	q.push({ sy,sx,0 });
	map[sy][sx] = 1;

	cout << bfs() << "회";

	return 0;
}
