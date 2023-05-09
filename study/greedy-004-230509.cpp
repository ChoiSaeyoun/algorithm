//Greedy TOP-4

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Score { int cd, it; };
bool compare(Score a, Score b) {
	return a.cd < b.cd;
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<Score> scores(n);

	for (int i = 0; i < n; i++) {
		cin >> scores[i].cd >> scores[i].it;
	}
	sort(scores.begin(), scores.end(), compare);

	int cnt = 0;
	int highest = scores[0].it;
	for (int i = 0; i < n; i++) {
		if (scores[i].it > highest)continue;
		else highest = scores[i].it;
		cnt++;
	}
	cout << cnt;

	return 0;
}