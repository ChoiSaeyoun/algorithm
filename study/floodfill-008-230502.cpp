//level 37-7
//친구 만나러 가는길

#include <iostream>
#include <queue>
using namespace std;

struct Node { int y, x, level; };
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
queue<Node>q;
vector<vector<int>>visited;
vector<vector<char>>map;
int n, m;

int bfs(int sy, int sx, int ey, int ex) {
	while (!q.empty())q.pop();
	for (auto i = visited.begin(); i != visited.end(); i++) {
		fill(i->begin(), i->end(), 0);
	}
	visited[sy][sx] = 1;
	q.push({ sy,sx,0 });
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (map[ny][nx] == 'x')continue;
			if (visited[ny][nx] == 1)continue;
			if (ny == ey && nx == ex)return now.level + 1;
			visited[ny][nx] = 1;
			q.push({ ny,nx,now.level + 1 });
		}
	}
	return -1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int sx, sy, cx, cy, ex, ey;
	char input;

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		map.push_back({});
		visited.push_back({});
		for (int x = 0; x < m; x++) {
			visited[y].push_back(0);
			cin >> input;
			map[y].push_back(input);
			if (input == 'S') {
				sx = x; sy = y;
			}
			if (input == 'C') {
				cx = x; cy = y;
			}
			if (input == 'D') {
				ex = x; ey = y;
			}
		}
	}

	cout << bfs(sy, sx, cy, cx) + bfs(cy, cx, ey, ex);

	return 0;
}
