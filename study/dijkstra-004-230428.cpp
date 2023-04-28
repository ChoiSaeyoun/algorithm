//level 36-2
//≈Î«‡∑·

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
int s, e;

int dijkstra(priority_queue<Node> q, vector<vector<Node>> alist, vector<int> result, int inc) {

	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.w > result[now.n])continue;
		for (int i = 0; i < alist[now.n].size(); i++) {
			Node next = alist[now.n][i];
			int W = now.w + next.w + inc;
			if (W < result[next.n]) {
				result[next.n] = W;
				q.push({ next.n,W });
			}
		}
	}
	return result[e];
}
int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M, K;
	cin >> N >> M >> K;
	cin >> s >> e;

	priority_queue<Node> q;
	vector <vector<Node>> alist(N + 1);
	vector<int> result(N + 1);
	fill(result.begin(), result.end(), 21e8);

	int from, to, w;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;
		alist[from].push_back({ to,w });
		alist[to].push_back({ from,w });
	}

	result[s] = 0;
	q.push({ s,0 });

	int inc = 0, input;
	for (int i = 0; i < K + 1; i++) {
		if (i != 0) {
			cin >> input;
			inc += input;
		}
		cout << dijkstra(q, alist, result, inc) << "\n";
	}

	return 0;
}
