#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define n first
#define m second


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {

	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int f = 0; f < t; f++) {
		int board[51][51] = {};
		int vis[51][51]={};
		int xx, yy;
		int a, b, k;

		cin >> b >> a >> k;
		for (int x = 0; x < k; x++) {
				cin >> yy >>xx;
				board[xx][yy] = 1;
		}

		int cnt = 0;
		for (int x = 0; x < a; x++) {
			for (int y = 0; y < b; y++) {
				if (board[x][y] == 1 && vis[x][y] == 0) {
					cnt++;
					queue<pair<int, int>>Q;
					vis[x][y] = 1;
					Q.push({ x,y });
					while (!Q.empty()) {
						pair<int, int>now = Q.front(); Q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = now.n + dx[i];
							int ny = now.m + dy[i];
							if (nx < 0 || nx >= a || ny < 0 || ny >= b)continue;
							if (vis[nx][ny] == 1 || board[nx][ny] == 0)continue;
							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}

			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
