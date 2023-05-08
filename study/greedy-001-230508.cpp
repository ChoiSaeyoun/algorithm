//입력 : N개의 물질이 살 수 있는 최저/최고 온도 쌍
//출력 : 모든 물질이 살 수 있는 특정 온도의 보관소 최소 개수

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cell { int s, e; };
bool compare(cell a, cell b) { return a.s > b.s; };

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, usedCnt = 0, ans = 0;
	cin >> n;
	vector<cell> cells(n);
	vector<int> used(n, 0);
	for (int i = 0; i < n; i++)cin >> cells[i].s >> cells[i].e;
	sort(cells.begin(), cells.end(), compare);

	for (int j = 0; j < n; j++) {
		cell now = cells[j];
		if (used[j] == 1)continue;
		used[j] = 1;
		usedCnt++;
		ans++;

		for (int i = j + 1; i < n; i++) {
			if (used[i] == 1)continue;

			cell next = cells[i];
			if (now.s > next.e)continue;

			used[i] = 1;
			usedCnt++;
		}

		if (usedCnt == n) break;
	}

	cout << ans;

	return