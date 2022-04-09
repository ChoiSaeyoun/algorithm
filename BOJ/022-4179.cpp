#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

char board[1000][1000];
int dis[1000][1000];
int dis2[1000][1000];
int r, c;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {

	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;

	fill(&dis[0][0], &dis[r][c], -1);
	fill(&dis2[0][0], &dis2[r][c], -1);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				Q.push({ i,j });
				dis[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				dis2[i][j] = 0;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int>now = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
			if (board[nx][ny] == '#' || dis[nx][ny] >= 0)continue;
			Q.push({ nx,ny });
			dis[nx][ny] = dis[now.x][now.y] + 1;
		}
	}
	while (!Q2.empty()) {
		pair<int, int>now = Q2.front(); Q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dis2[now.x][now.y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dis2[nx][ny] >= 0)continue;
			if (dis[nx][ny]!=-1&&dis[nx][ny] <= dis2[now.x][now.y] + 1)continue;
			Q2.push({ nx,ny });
			dis2[nx][ny] = dis2[now.x][now.y] + 1;
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}
