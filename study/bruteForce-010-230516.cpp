//level 42-8
//레드 마운틴

#include<iostream>
using namespace std;

int n;
int map[15][15];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int used[15][15];
int flag = 0;

void run(int nowY, int nowX) {
	if (nowY == n - 1 && nowX == n - 1) {
		flag = 1; return;
	}
	for (int i = 0; i < 4; i++) {
		int nextY = nowY + dir[i][0];
		int nextX = nowX + dir[i][1];
		if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)continue;
		if (map[nextY][nextX] == 1)continue;
		if (used[nextY][nextX] == 1)continue;
		used[nextY][nextX] = 1;
		run(nextY, nextX);
	}
}
int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	run(0, 0);
	if (flag == 1)cout << "가능";
	else cout << "불가능";

	return 0;
}