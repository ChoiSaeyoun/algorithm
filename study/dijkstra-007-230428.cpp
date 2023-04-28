//level 36-5
//무서운 시어머니

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node { int y, x, w; };
bool operator<(Node b, Node a) { return a.w < b.w; };
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	int Y, X, N;
	cin >> Y >> X >> N;

	vector<vector<int>> map(N);
	vector<vector<int>> result(N, vector<int>(N, 21e8));
	priority_queue<Node>q;

	int w;
	for (int y = 0; y < N; y++) {
		map.push_back({});
		for (int x = 0; x < N; x++) {
			cin >> w;
			map[y].push_back(w);
		}
	}

	result[Y][X] = map[Y][X];
	q.push({ Y,X,map[Y][X] });

	while (!q.empty()) {
		Node now = q.top(); q.pop();
		if (now.w > result[now.y][now.x])continue;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (map[ny][nx] == -1) {
				result[ny][nx] = -1; continue;
			}
			int W = now.w + map[ny][nx];
			if (W < result[ny][nx]) {
				result[ny][nx] = W;
				q.push({ ny,nx,W });
			}
		}
	}

	int max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (result[y][x] > max)max = result[y][x];
		}
	}

	cout << max;

	return 0;
}
