//level 38-4
//천지창조

#include <iostream>
#include <queue>
#include<vector>
using namespace std;

string map[8];
struct Node { int y, x, level; };
queue<Node>q, p;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int used[8][9];

int bfs(int sy, int sx) {
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		p.push({ now.y,now.x,0 });
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)continue;
			if (used[ny][nx] == 1)continue;
			if (map[ny][nx] == '_')continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,0 });
		}
	}
	while (!p.empty()) {
		Node now = p.front(); p.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)continue;
			if (used[ny][nx] == 1)continue;
			if (map[ny][nx] == '#')return now.level;
			used[ny][nx] = 1;
			p.push({ ny,nx,now.level + 1 });
		}
	}

	return -1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int sx, sy;
	for (int i = 0; i < 8; i++) {
		cin >> map[i];
	}
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 9; x++) {
			if (map[y][x] == '#') {
				cout << bfs(y, x);
				return 0;
			}
		}
	}
	return 0;
}
