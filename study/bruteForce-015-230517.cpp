//level 42.5-5
//독수리 3형제

#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

int foods[6];
int endTurn;
int eatRange[3][2] = { {0,2},{3,5},{1,4} };
int startId, endId;
int maxScore = -21e8;
int path[100];

int getScore() {
	int foods2[6];
	memcpy(foods2, foods, 6 * sizeof(int));
	int score = 0;
	for (int turn = 0; turn < endTurn; turn++) {
		int sum = 0;
		for (int i = turn * 3; i < turn * 3 + 3; i++) {
			sum += foods2[path[i]];
			foods2[path[i]] = 0;
		}
		score += sum * (pow(2, turn));
	}
	return score;
}
void Eat(int eatCnt, int startId, int endId) {
	if (eatCnt == 3 * endTurn) {
		int score = getScore();
		if (maxScore < score) {
			maxScore = score;
		}
		return;
	}
	for (int i = startId; i <= endId; i++) {
		path[eatCnt] = i;
		Eat(eatCnt + 1, eatRange[(eatCnt + 1) % 3][0], eatRange[(eatCnt + 1) % 3][1]);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 6; i++)cin >> foods[i];
	cin >> endTurn;

	Eat(0, 0, 2);

	cout << maxScore;
	return 0;
}