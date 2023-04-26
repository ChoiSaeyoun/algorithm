//LEVEL 35-6
//정중앙대학교

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minH;
priority_queue<int> maxH;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int mid = 500;
	int n, a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a >= mid)minH.push(a);
		else maxH.push(a);
		if (b >= mid)minH.push(b);
		else maxH.push(b);

		int gap = minH.size() - maxH.size();
		if (gap > 0) {
			while (gap != 0) {
				maxH.push(mid);
				mid = minH.top(); minH.pop();
				gap -= 2;
			}
		}
		else if (gap < 0) {
			while (gap != 0) {
				minH.push(mid);
				mid = maxH.top(); maxH.pop();
				gap += 2;
			}
		}
		if (gap == 0)cout << mid << "\n";
	}

	return 0;
}