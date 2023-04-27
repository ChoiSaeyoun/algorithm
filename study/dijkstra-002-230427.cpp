//입력 : 시작, 끝 노드번호
//출력 : 루트마다 가장 큰 비용끼리의 최솟값

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int n, w;
};
bool operator < (Node b, Node a) {
	return a.w < b.w;
}
priority_queue<Node> q;
vector<vector<Node>> alist(5);
int result[5];
int s, e;
void init() {
	fill(result, result + 5, 21e8);
	result[s] = 0;
	alist[0] = { {1,8},{4,4},{3,10} };
	alist[1] = { {2,1} };
	alist[2] = { {3,2} };
	alist[4] = { {2,3},{3,5} };
	q.push({ s,0 });
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> s >> e;
	init();

	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (result[now.n] < now.w)continue;
		for (int i = 0; i < alist[now.n].size(); i++) {
			Node next = alist[now.n][i];
			int maxW = max(now.w, next.w);
			if (result[next.n] > maxW) {
				result[next.n] = maxW;
				q.push({ next.n,maxW });
			}
		}
	}
	cout << result[e];
	return 0;
}