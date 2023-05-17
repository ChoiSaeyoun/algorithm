//level 42.5-3
//수학이의 연산

#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int nums[10];
int cnt = 0;

int operate(int i, int a, int b) {
	if (i == 0) return (a - b) * (a + b);
	if (i == 1)return max(a, b);
	if (i == 2)return pow(a, 2) - pow(b, 2);
	if (i == 3)return pow(a + b, 2);
}
void run(int level, int result) {
	if (level == n) {
		if (result == 100) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		run(level + 1, operate(i, result, nums[level + 1]));
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	run(0, nums[0]);
	cout << cnt;
	return 0;
}