//level 41-4

#include<iostream>
using namespace std;

int n, cnt = 0;
void run(int level, int sum) {
	if (sum > 7)return;
	if (level == n) {
		if (sum == 7)cnt++;
		return;
	}
	for (int i = 0; i < 10; i++) {
		run(level + 1, sum + i);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;
	run(0, 0);
	cout << cnt;

	return 0;
}