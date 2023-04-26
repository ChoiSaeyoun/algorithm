//LEVEL 35-4
//통행료 몰래 올리기

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y, x, cost;
};
priority_queue<Node> q;
bool operator<(Node b, Node a) {
	if (a.cost < b.cost)return 1;
	if (a.cost > b.cost)return 0;

	if (a.y < b.y)return 1;
	if (a.y > b.y)return 0;

	return a.x < b.x;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, cost;

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> cost;
			if ((x >= y + 1) && cost != -1) {
				q.push({ y,x,cost });
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		Node tar = q.top(); q.pop();
		tar.cost *= 2;;
		q.push(tar);
	}

	cout << q.top().cost * 2 << "만원";

	return 0;
}