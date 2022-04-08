#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int board[500][500] = {};
int vis[500][500] = {};
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS(int i, int j) {

	queue<pair<int, int>> Q;
	Q.push({ i,j });
	vis[i][j] = 1;

	int sum = 1;

	while (!Q.empty()) {
		pair<int, int> now = Q.front(); Q.pop();
		for (int a = 0; a < 4; a++) {
			int nx = now.x + dx[a];
			int ny = now.y + dy[a];
			if (nx < 0 || nx >= n || ny<0 || ny>=m)continue;
			if (board[nx][ny] == 0 || vis[nx][ny] == 1)continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
			sum++;
		}
	}
	return sum;
}

int main() {

	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int max = 0,cnt=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1&&vis[i][j]==0) {
				int sum = BFS(i, j);
				if (max < sum) {
					max = sum;
				}
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << max;

	return 0;
}
