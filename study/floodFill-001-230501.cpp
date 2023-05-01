//ÀÔ·Â : X
//Ãâ·Â : ÃÑ ¼¶ÀÇ °³¼ö

#include <iostream>
#include <queue>
using namespace std;

struct Node { int y, x; };
queue<Node> q;
int map[5][6] = {
	0,0,1,1,1,1,
	0,0,1,0,0,1,
	0,1,0,1,0,1,
	0,1,0,0,1,1,
	1,0,1,1,0,0
};
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };

void floodfill(int y, int x) {

	while (!q.empty())q.pop();

	q.push({ y,x });
	map[y][x] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 6)continue;
			if (map[ny][nx] == 0)continue;
			map[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
}

int main() {
	int cnt = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 6; x++) {
			if (map[y][x] == 0)continue;
			floodfill(y, x);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
