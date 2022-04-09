#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int n, k;

int main() {

	//freopen("input.txt", "rt", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(dist, dist+100001, -1);
	queue<int>Q;
	Q.push(n);
	dist[n] = 0;
	while (dist[k] == -1) {
		int now = Q.front(); Q.pop();
		for (int i : {now - 1, now + 1, now * 2}) {
			if (i < 0 || i>100002)continue;
			if (dist[i] >= 0)continue;
			dist[i] = dist[now] + 1;
			Q.push(i);
		}
	}
	cout << dist[k];

	return 0;
}
