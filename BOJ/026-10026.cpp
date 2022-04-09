#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

string board[101];
int vis[101][101];
int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {

	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				cnt++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					pair<int, int>now = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = now.x + dx[i];
						int ny = now.y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != board[now.x][now.y])continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
	}
	cout << cnt << " ";

	cnt = 0;
	fill(&vis[0][0], &vis[n][n], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				cnt++;
				if (board[i][j] == 'G') board[i][j] = 'R';
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					pair<int, int>now = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = now.x + dx[i];
						int ny = now.y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (board[nx][ny] == 'G') board[nx][ny] = 'R';
						if (vis[nx][ny] == 1 || board[nx][ny] != board[now.x][now.y])continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
	}
	cout << cnt<<" ";

	return 0;
}
