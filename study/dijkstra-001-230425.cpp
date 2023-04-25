#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int n;
	int price;
};
vector<vector<Node>> alist(6);
priority_queue<Node> q;
int result[6];

bool operator<(Node b, Node a) {
	return a.price < b.price;
}

void init() {
	for (int i = 0; i < 6; i++)result[i] = 21e8;
	result[0] = 0;

	alist[0] = { {1,5},{2,10},{3,7} };
	alist[1] = { {0,5},{5,9} };
	alist[2] = { {5,1} };
	alist[3] = { {4,1} };
	alist[4] = { {5,6} };

	q.push({ 0,0 });
}
int main() {
	init();

	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		if (result[now.n] < now.price)continue;

		for (int i = 0; i < alist[now.n].size(); i++) {
			Node next = alist[now.n][i];
			int priceSum = now.price + next.price;
			if (result[next.n] > priceSum) {
				result[next.n] = priceSum;
				q.push({ next.n,priceSum });
			}
		}
	}

	return 0;
}