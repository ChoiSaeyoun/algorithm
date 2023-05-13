//level 41-2

#include<iostream>
#include<algorithm>
using namespace std;

int map[160];
int dp[160];
const int MIN = -21e8;
int jump[2] = { 2,7 };
int maxScore = -21e8;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> map[i];
	fill(dp, dp + 160, MIN);
	dp[0] = 0;

	for (int now = 0; now <= n; now++) {
		for (int i = 0; i < 2; i++) {
			int next = now + jump[i];
			if (next >= n + 1) {
				maxScore = max(maxScore, dp[now]);
			}
			int nextScore = dp[now] + map[next];
			if (dp[next] < nextScore)dp[next] = nextScore;
		}
	}

	cout << maxScore;

	return 0;
}