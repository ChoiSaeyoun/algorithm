//level 40-1

#include<iostream>
using namespace std;

int map[5][5];
int dir[5][5];
int dp[5][5];
enum {
	R, D, N
};
const int MAX = 21e8;
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[i][4] = MAX;
		dp[4][i] = MAX;
	}

	dir[3][3] = N;
	dp[3][3] = 0;
	for (int y = 3; y >= 0; y--) {
		for (int x = 3; x >= 0; x--) {
			if (y == 3 && x == 3)continue;
			if (dp[y + 1][x] < dp[y][x + 1]) {
				dp[y][x] = map[y][x] + dp[y + 1][x];
				dir[y][x] = D;
			}
			else {
				dp[y][x] = map[y][x] + dp[y][x + 1];
				dir[y][x] = R;
			}
		}
	}
	int ny = 0, nx = 0;
	while (1) {
		cout << ny << "," << nx << "\n";
		if (dir[ny][nx] == R)nx++;
		else if (dir[ny][nx] == D)ny++;
		else break;
	}

	return 0;
}