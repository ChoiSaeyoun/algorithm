//level 36-4
//포스터 붙이기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int C, P, K, A, B;
struct Node {
	int n, w;
};
bool operator<(Node b, Node a) {
	return a.w < b.w;
}

int dijkstra(int s, int e, vector<vector<Node>> alist, vector<int> result, priority_queue<Node>q) {
	result[s] = 0;
	q.push({ s,0 });
	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.n == e)return result[e];
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

	cin >> C >> P >> K >> A >> B;

	vector<vector<Node>> alist(P + 1);
	vector<int> result(P + 1, 21e8);
	priority_queue<Node>q;

	int from, to, w;
	for (int i = 0; i < C; i++) {
		cin >> from >> to >> w;
		alist[from].push_back({ to,w });
		alist[to].push_back({ from,w });
	}

	int ka = dijkstra(K, A, alist, result, q);
	int kb = dijkstra(K, B, alist, result, q);
	int ab = dijkstra(A, B, alist, result, q);

	cout << min(ka + ab, kb + ab);

	return 0;
}
