//level 40-3

#include<iostream>
#include<algorithm>
using namespace std;

int map[12];
int dp[12];
const int MIN = -21e8;
int maxScore;

void Jump(int now, int next) {
	if (next >= 12)maxScore = max(maxScore, dp[now]);
	int nextScore = map[next] + dp[now];
	if (dp[next] < nextScore) {
		dp[next] = nextScore;
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}
	fill(dp, dp + 12, MIN);
	dp[0] = 0;

	for (int i = 0; i < 12; i++) {
		if (dp[i] == MIN)continue;
		Jump(i, i + 2);
		Jump(i, i + 3);
		Jump(i, i * 2);
	}
	cout << maxScore;

	return 0;
}