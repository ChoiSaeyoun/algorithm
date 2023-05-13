//level 41-3

#include<iostream>
using namespace std;

int T, n;
int coins[10];
int memo[3010];
const int M = 21e8;
int getCnt(int price) {
	if (memo[price] != M)return memo[price];
	for (int i = n - 1; i >= 0; i--) {
		int rest = price - coins[i];
		if (rest < 0)continue;
		int restCnt = getCnt(rest);
		if (memo[price] > restCnt + 1)memo[price] = restCnt + 1;
	}
	return memo[price];
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> T >> n;
	fill(memo, memo + 3010, M);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		memo[coins[i]] = 1;
	}

	int ans = getCnt(T);
	if (ans == M)cout << "imposiible";
	else cout << ans;

	return 0;
}


//다른 방법

//#include<iostream>
//using namespace std;
//
//int dp[3001];
//int target;
//int N;
//int coins[100];
//const int MAX = 21e8;
//int main()
//{
//	freopen_s(new FILE*, "input.txt", "r", stdin);
//
//	cin >> target >> N;
//	for (int i = 0; i < N; i++)cin >> coins[i];
//	fill(dp, dp + 3001, MAX);
//	dp[0] = 0;
//
//	for (int now = 0; now < target; now++) {
//		if (dp[now] == MAX)continue;
//		for (int i = 0; i < N; i++) {
//			int next = now + coins[i];
//			if (dp[now] + 1 < dp[next])dp[next] = dp[now] + 1;
//		}
//	}
//	if (dp[target] != MAX)cout << dp[target];
//	else cout << "impossible";
//
//	return 0;
//}