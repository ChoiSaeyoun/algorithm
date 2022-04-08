#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

string board[500];
int dist[500][500];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	fill(&dist[0][0], &dist[n][m], -1);
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;
	while (!Q.empty()) {
		pair<int, int> now = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (board[nx][ny] == '0' || dist[nx][ny] >=0)continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1;

	return 0;
}
