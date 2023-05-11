//level 40-4

#include<iostream>
#include<algorithm>
using namespace std;

int map[7][5];
int dp[7][5];
const int MIN = -21e8;
int dir[3][2] = { 1,-1,1,0,1,1 };

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int y = 0; y < 7; y++) {
		for (int x = 1; x < 4; x++) {
			cin >> map[y][x];
		}
	}
	fill(&dp[0][0], &dp[6][5], MIN);
	for (int x = 1; x < 4; x++) {
		if (map[6][x] == 0)continue;
		dp[6][x] = map[6][x];
	}

	for (int y = 5; y >= 0; y--) {
		for (int x = 1; x <= 3; x++) {
			if (map[y][x] == 0)continue;
			for (int i = 0; i < 3; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				if (dp[y][x] < map[y][x] + dp[ny][nx])dp[y][x] = map[y][x] + dp[ny][nx];
			}
		}
	}
	cout << dp[0][1];
	return 0;
}