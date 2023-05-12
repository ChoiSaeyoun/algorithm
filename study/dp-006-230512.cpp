//입력 : X
//출력 : (0번부터 3 or 5 칸씩 점프)
//		15번에 도착했을 때 획득 가능한 최고 점수

#include<iostream>
using namespace std;

int score[16] = { 0,3,5,-99,7,4,-100,5,4,1000,1,5,9,2,6,0 };
const int MIN = -21e8;
int memo[16];

int getMax(int n) {
	if (n == 0)return 0;
	if (n < 3)return MIN;
	if (memo[n] != MIN)return memo[n]; //순서 주의

	int a = getMax(n - 3);
	int b = getMax(n - 5);

	int ret = max(a, b) + score[n];
	memo[n] = ret;
	return ret;
}
int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	fill(memo, memo + 16, MIN);
	cout << getMax(15);

	return 0;
}