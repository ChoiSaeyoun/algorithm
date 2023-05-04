//level 38-3
//해물새우파전

#include <iostream>
#include <queue>
#include<vector>
using namespace std;

const int N = 7;
struct Node { int y, x, level; };
queue<Node>q;
vector<string>map(N);
int used[N][N];
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };

bool isValid(int sy, int sx, int target) {
	memset(used, 0, N * N * sizeof(int));
	while (!q.empty())q.pop();

	int len = 0;
	if (target == 1)len = 3;
	else len = 4;

	q.push({ sy,sx,1 });
	used[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.level == len)return true;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (used[ny][nx] == 1)continue;
			if (map[ny][nx] == target + '0') {
				return false;
			}
			used[ny][nx] = 1;
			q.push({ ny,nx,now.level + 1 });
		}
	}
	return true;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1' && !isValid(y, x, 1)) {
				cout << "fail"; return 0;
			}
			if (map[y][x] == '2' && !isValid(y, x, 2)) {
				cout << "fail"; return 0;
			}
		}
	}
	cout << "pass";

	return 0;
}
