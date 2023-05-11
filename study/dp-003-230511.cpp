//level 40-2

#include<iostream>
using namespace std;

int dp(int x) {
	if (x == 1)return 1;
	if (x == 2)return 2;
	int ret = dp(x - 2) + dp(x - 1);
	return ret;
}
int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	cout << dp(n);

	return 0;
}