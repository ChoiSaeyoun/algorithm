//level 42-4
//최소 동전 교환기

#include<iostream>
#include<algorithm>
using namespace std;

int target;
int coins[3] = { 10,40,60 };
int minLevel = 21e8;
void run(int level, int sum) {
	if (sum > target)return;
	if (level >= minLevel)return;
	if (sum == target) {
		minLevel = level;
	}
	for (int i = 0; i < 3; i++) {
		run(level + 1, sum + coins[i]);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> target;
	run(0, 0);
	cout << minLevel;

	return 0;
}