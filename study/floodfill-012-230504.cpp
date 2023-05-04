//level 38-2
//¿©¿Õ¹úÀÇ ¾ËÁý

#include <iostream>
#include <queue>
using namespace std;

struct Node { int y, x, cnt; };
queue<Node>q;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int visited[4][9];
int map[4][9];

int bfs(int ty, int tx) {
	int ret = 1;
	q.push({ ty,tx,1 });
	visited[ty][tx] = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 9)continue;
			if (visited[ny][nx] == 1)continue;
			if (map[ny][nx] != map[now.y][now.x])continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx,now.cnt + 1 });
			ret++;
		}
	}
	return ret;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int max = 0, maxi = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			if (visited[y][x] == 0) {
				int sum = bfs(y, x);
				if (max < sum) {
					max = sum; maxi = map[y][x];
				}
			}
		}
	}

	cout << max * maxi;
	return 0;
}
