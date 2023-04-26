//LEVEL 35-2
//브르주아 여행사

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	char y, x;
	int w;
};

bool operator<(Node b, Node a) {
	return a.w > b.w;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, w;
	priority_queue<Node> q;

	cin >> n;
	for (char y = 0; y < n; y++) {
		for (char x = 0; x < n; x++) {
			cin >> w;
			q.push({ 'A' + y,'A' + x,w });
		}
	}

	for (int i = 0; i < 3; i++) {
		Node ret = q.top(); q.pop();
		cout << ret.y << "-" << ret.x << " " << ret.w << "\n";
	}

	return 0;
}