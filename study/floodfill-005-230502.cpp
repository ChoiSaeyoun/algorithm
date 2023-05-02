//level 37-4
//무인도의 크기

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
queue<Node>q;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int map[4][4];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	q.push({ 0,0 });
	map[0][0] = 0;
	int cnt = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)continue;
			if (map[ny][nx] == 0)continue;
			map[ny][nx] = 0;
			q.push({ ny,nx });
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
