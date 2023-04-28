//level 36-1
//알뜰 기차여행

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int n, w;
};
bool operator<(Node b, Node a) {
	return a.w < b.w;
}
priority_queue<Node> q;

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, T;
	int x, n, w;

	cin >> N >> T;

	vector<vector<Node>> alist(N);
	vector<int> result(N);

	for (int i = 0; i < T; i++) {
		cin >> x >> n >> w;
		alist[x].push_back({ n,w });
	}

	fill(result.begin(), result.end(), 21e8);
	result[0] = 0;
	q.push({ 0,0 });

	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.w > result[now.n])continue;
		for (int i = 0; i < alist[now.n].size(); i++) {
			Node next = alist[now.n][i];
			int W = now.w + next.w;
			if (W < result[next.n]) {
				result[next.n] = W;
				q.push({ next.n,W });
			}
		}
	}

	if (result[N - 1] != 21e8)cout << result[N - 1];
	else cout << "impossible";

	return 0;
}
