//level 38-5
//¾È³ª¿Í ¿¤»ç

#include <iostream>
#include <queue>
#include<vector>
#include<cstdlib>
using namespace std;

struct Node { int y1, x1, y2, x2, level; };
queue<Node>q;
int used[5][5][5][5];
int dir1[8][2] = { -1,0,1,0,0,-1,0,1,-1,-1,1,-1,-1,1,1,1 };
int dir2[5][2] = { -1,0,1,0,0,-1,0,1,0,0 };
int N, sy1, sx1, sy2, sx2;
vector<string> map;

int bfs() {
	q.push({ sy1, sx1, sy2, sx2 ,0 });
	used[sy1][sx1][sy2][sx2] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.y1 == now.y2 && now.x1 == now.x2) return now.level;
		for (int i = 0; i < 8; i++) {
			if (abs(now.y1 - now.y2) <= 2 && abs(now.x1 - now.x2) <= 2 && i == 4) {
				break;
			}
			int ny1 = now.y1 + dir1[i][0];
			int nx1 = now.x1 + dir1[i][1];

			if (ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= N)continue;

			for (int j = 0; j < 5; j++) {
				int ny2 = now.y2 + dir2[j][0];
				int nx2 = now.x2 + dir2[j][1];

				if (ny2 < 0 || nx2 < 0 || ny2 >= N || nx2 >= N)continue;
				if (map[ny1][nx1] == '#' || map[ny2][nx2] == '#')continue;
				if (used[ny1][nx1][ny2][nx2])continue;

				used[ny1][nx1][ny2][nx2] = 1;
				q.push({ ny1,nx1,ny2,nx2,now.level + 1 });
			}
		}
	}
	return -1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	string s;
	for (int y = 0; y < N; y++) {
		cin >> s;
		map.push_back(s);
	}
	cin >> sy1 >> sx1 >> sy2 >> sx2;
	cout << bfs() << " sec";


	return 0;
}
