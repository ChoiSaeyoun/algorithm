//level 37-1
//바이러스 2군데 투여

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

	int N, Y1, Y2, X1, X2;
	cin >> N >> Y1 >> X1 >> Y2 >> X2;

	vector<vector<int>>map(N, vector<int>(N, 0));

	q.push({ Y1,X1 });
	q.push({ Y2,X2 });
	map[Y1][X1] = 1;
	map[Y2][X2] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (map[ny][nx] > 9)map[ny][nx] = 9;
			q.push({ ny,nx });
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}

	return 0;
}
