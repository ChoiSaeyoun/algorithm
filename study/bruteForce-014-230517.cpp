//level 42.5-4
//∫“»≠ªÏ ΩÓ±‚

#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int nums[8];
int used[8];
int path[8];
int maxScore = -21e8;
int maxPath[8];
int maxLevel;

void run(int start, int level, int score) {
	if (((start == n - 2) && (used[n - 1] == 1)) || start == n - 1) {
		if (maxScore < score) {
			maxScore = score;
			memcpy(maxPath, path, 8 * sizeof(int));
			maxLevel = level;
		}
		return;
	}
	for (int i = start + 1; i < n; i++) {
		if (used[i] == 1)continue;

		path[level] = nums[i];
		int backup[8];
		memcpy(backup, used, 8 * sizeof(int));
		if (i + 1 < n) used[i + 1] = 1;
		if (i - 1 > 0)used[i - 1] = 1;

		run(i, level + 1, score + nums[i]);

		path[level] = 0;
		memcpy(used, backup, 8 * sizeof(int));
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)cin >> nums[i];
	run(-1, 0, 0);

	for (int i = 0; i < maxLevel; i++) {
		if (i == maxLevel - 1)cout << maxPath[i] << "=";
		else cout << maxPath[i] << "+";
	}
	cout << maxScore;

	return 0;
}