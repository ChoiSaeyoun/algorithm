//level 42.5-1
//가로 큐브 돌리기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cube[5][5];
int start[5];
int maxScore = -21e8;

int getScore() {
	int score = 1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int y = 0; y < n; y++) {
			int x = start[y] + i;
			if (x >= n)x -= n;;
			sum += cube[y][x];
		}
		score *= sum;
	}
	return score;
}
void run(int y) {
	if (y == n) {
		maxScore = max(maxScore, getScore());
		return;
	}
	for (int x = 0; x < n; x++) {
		start[y] = x;
		run(y + 1);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> cube[y][x];
		}
	}
	run(0);
	cout << maxScore << "점";


	return 0;
}