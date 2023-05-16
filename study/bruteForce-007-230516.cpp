//level 42-5
//10을 만들자

#include<iostream>
using namespace std;

int n, cnt = 0;

void run(int level, int sum) {
	if (level == n) {
		if (sum == 10)cnt++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		run(level + 1, sum + i);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	run(0, 0);
	cout << cnt;
	return 0;
}