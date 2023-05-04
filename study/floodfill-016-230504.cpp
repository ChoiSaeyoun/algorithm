//level 38-6
//BFS 배달맨

#include <iostream>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;

struct Node { int y, x, level; };
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
queue<Node>q;
int used[10][10];
vector<string>map;
int m, n;

int bfs(int* sy, int* sx, int target) {
	while (!q.empty())q.pop();
	for (int i = 0; i < m; i++) {
		memset(used[i], 0, n * sizeof(int));
	}

	q.push({ *sy,*sx,0 });
	used[*sy][*sx] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (map[now.y][now.x] - '0' == target) {
			*sy = now.y; *sx = now.x;
			return now.level;
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n)continue;
			if (map[ny][nx] == '#')continue;
			if (used[ny][nx] == 1)continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,now.level + 1 });
		}
	}

	return -1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> m >> n;

	string s;
	for (int y = 0; y < m; y++) {
		cin >> s;
		map.push_back(s);
	}

	int sy = 0, sx = 0;
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		sum += bfs(&sy, &sx, i);
	}
	cout << sum << "회";

	return 0;
}
