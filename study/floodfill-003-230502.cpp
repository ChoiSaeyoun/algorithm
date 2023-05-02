//level 37-2
//BBQ ¿Â¿€

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node { int y, x, level; };
queue<Node>q;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	vector<vector<int>>map(n);
	int input;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> input;
			map[y].push_back(input);
		}
	}

	int sy, sx;
	cin >> sy >> sx;
	q.push({ sy,sx,0 });
	map[sy][sx] = 1;

	int res = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (map[ny][nx] == 1)continue;
			map[ny][nx] = 1;
			q.push({ ny,nx,now.level + 1 });
			res = now.level + 1;
		}
	}
	cout << res;

	return 0;
}
