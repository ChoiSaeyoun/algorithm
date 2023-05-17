//level 42.5-2
//∆¯≈∫ ≈ı«œ ¿Âº“ º±¡§

#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

string map[4];
int N;
struct Node { int y, x; };
Node path[5];
Node maxPath[5];
int used[4][4];

int dir[5][2] = { 0,0,1,0,-1,0,0,1,0,-1 };
int dead[100];
int maxCnt = -21e8;

int compare(Node a, Node b) {
	return map[a.y][a.x] < map[b.y][b.x];
}
int getCnt() {
	int cnt = 0;
	memset(dead, 0, 100 * sizeof(int));
	for (int p = 0; p < N; p++) {
		Node now = path[p];
		for (int i = 0; i < 5; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)continue;
			if (map[ny][nx] == '_')continue;
			if (dead[map[ny][nx]] == 1)continue;
			dead[map[ny][nx]] = 1;
			cnt++;
		}
	}
	return cnt;
}
void run(int level) {
	if (level == N) {
		int pathCnt = getCnt();
		if (pathCnt > maxCnt) {
			maxCnt = pathCnt;
			memcpy(maxPath, path, 5 * sizeof(Node));
		}
		return;
	}
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == '_')continue;
			if (used[y][x] == 1)continue;
			used[y][x] = 1;
			path[level] = { y,x };
			run(level + 1);
			used[y][x] = 0;
		}
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 4; i++)cin >> map[i];
	cin >> N;

	run(0);
	sort(maxPath, maxPath + N, compare);
	for (int i = 0; i < N; i++)cout << map[maxPath[i].y][maxPath[i].x] << " ";

	return 0;
}