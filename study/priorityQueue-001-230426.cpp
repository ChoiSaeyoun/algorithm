//LEVEL 34-6
//금 나와라 황금보자기

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int w;
	int gold;
};

bool operator<(Node b, Node a) {
	if (a.w < b.w) return 1;
	if (a.w > b.w) return 0;
	return a.gold > b.gold;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, w, cnt = 0;
	priority_queue<Node> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		q.push({ w,1 });
	}

	while (1) {
		Node a = q.top(); q.pop();
		if (a.gold == 0)break; cnt++;
		Node b = q.top(); q.pop();
		if (b.gold == 0)break; cnt++;

		Node newy = { b.w * 2, 0 };
		q.push(newy);
	}

	cout << cnt;

	return 0;
}