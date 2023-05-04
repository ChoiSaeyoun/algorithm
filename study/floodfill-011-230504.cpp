//level 38-1
//더블 리모콘

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int s, d;
struct Node { int num, level; };
queue<Node>q;
int used[MAX + 1];

void push(int num, int level) {
	if (num < 0 || num>MAX)return;
	if (used[num] == 1)return;
	used[num] = 1;
	q.push({ num,level });
}
int bfs() {
	q.push({ s,0 });
	used[s] = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.num == d)return now.level;
		push(now.num / 2, now.level + 1);
		push(now.num * 2, now.level + 1);
		push(now.num + 1, now.level + 1);
		push(now.num - 1, now.level + 1);
	}
	return -1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> s >> d;

	cout << bfs();

	return 0;
}
