//level 42-2
//Best Number 선정하기

#include<iostream>
using namespace std;

int input[5];
int path[5];
int MIN = 21e8, MAX = -21e8;
int used[5];
int getAns(int path[5]) {
	int ans = path[0] * path[1] - path[2] * path[3] + path[4];
	return ans;
}
void run(int level) {
	if (level == 5) {
		int ans = getAns(path);
		MIN = min(MIN, ans);
		MAX = max(MAX, ans);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		path[level] = input[i];
		run(level + 1);
		used[i] = 0;
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 5; i++)cin >> input[i];
	run(0);
	cout << MAX << "\n" << MIN;
	return 0;
}