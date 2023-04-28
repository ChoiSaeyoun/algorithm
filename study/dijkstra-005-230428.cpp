//level 36-3
//오프라인 모임

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

void dijkstra(int s, int e, int i, vector<vector<Node>> alist, priority_queue<Node> q, vector<int> result, vector<int>& sum) {
	result[s] = 0;
	q.push({ s,0 });
	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.n == e) {
			sum[i] += now.w;
			return;
		}
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
}

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M, P;
	cin >> N >> M >> P;

	vector <vector<Node>> alist(N + 1);
	priority_queue<Node> q;
	vector<int> result(N + 1);
	vector<int> sum(N + 1);

	int from, to, w;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;
		alist[from].push_back({ to,w });
	}
	fill(result.begin(), result.end(), 21e8);

	for (int s = 1; s <= N; s++) {
		dijkstra(s, P, s, alist, q, result, sum);
		dijkstra(P, s, s, alist, q, result, sum);
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < sum[i])max = sum[i];
	}
	cout << max;

	return 0;
}
