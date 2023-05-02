//level 37-8
//¼¶ Ã£¾Æ »ï¸¸¸®

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node { int y, x; };
queue<Node>q;
vector<vector<int>>map;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
int n, m;

void bfs(int sy, int sx) {
	map[sy][sx] = 0;
	q.push({ sy,sx });
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (map[ny][nx] == 0)continue;
			map[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m;
	int input;
	for (int y = 0; y < n; y++) {
		map.push_back({});
		for (int x = 0; x < m; x++) {
			cin >> input;
			map[y].push_back(input);
		}
	}
	int cnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == 1) {
				bfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
