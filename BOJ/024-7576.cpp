#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int board[1000][1000];
int dist[1000][1000];
int m, n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {

	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	queue<pair<int, int>>Q;
	fill(&dist[0][0], &dist[m][n], -1);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				dist[i][j] = 0;
				Q.push({ i,j });
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> now = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx<0 || nx>=m || ny<0 || ny>=n)continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != 0)continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			Q.push({ nx,ny });
			board[nx][ny] = 1;
		}
	}
	int mx = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			mx = max(dist[i][j], mx);
		}
	}
	cout << mx;
	return 0;
}
