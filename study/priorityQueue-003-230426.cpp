//LEVEL 35-3
//¿¬¼âÆøÅº

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int y, x;
	int num;
};
priority_queue<Node> q;
vector<vector<int>> map;
int dir[5][2] = {
	0,0,
	0,1,
	0,-1,
	1,0,
	-1,0
};
bool operator<(Node b, Node a) {
	return a.num < b.num;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, num, cnt = 0;

	cin >> n;
	for (int y = 0; y < n; y++) {
		map.push_back({});
		for (int x = 0; x < n; x++) {
			cin >> num;
			map[y].push_back(num);
			q.push({ y,x,num });
		}
	}

	while (1) {
		if (cnt == n * n)break;

		Node tar = q.top(); q.pop();
		if (map[tar.y][tar.x] == -1)continue;

		for (int i = 0; i < 5; i++) {
			int newY = tar.y + dir[i][0];
			int newX = tar.x + dir[i][1];
			if (newY < 0 || newX < 0 || newY >= n || newX >= n)continue;
			if (map[newY][newX] == -1)continue;
			map[newY][newX] = -1;
			cnt++;
		}
	}

	if (!q.empty())cout << q.top().num - 1 << "ÃÊ";
	else cout << n * n << "ÃÊ";

	return 0;
}