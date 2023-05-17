//level 42.5-6
//디자이너의 손길

#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;

char input[100];
int n;
int maxScore = -21e8;
int score;
int len;

int getScore() {
	int score = 0;
	for (int i = 0; i < len - 1; i++) {
		int gap = abs(input[i + 1] - input[i]);
		if (gap == 0)score -= 50;
		else if (gap <= 5)score += 3;
		else if (gap >= 20)score += 10;
	}
	return score;
}
void change(int changeCnt) {
	if (changeCnt == n + 1) {
		score = getScore();
		if (score > maxScore)maxScore = score;
		return;
	}
	for (int now = 0; now < len - 1; now++) {
		for (int next = now + 1; next < len; next++) {
			swap(input[now], input[next]);
			change(changeCnt + 1);
			swap(input[next], input[now]);
		}
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> input >> n;
	len = strlen(input);
	change(1);
	cout << maxScore;
	return 0;
}