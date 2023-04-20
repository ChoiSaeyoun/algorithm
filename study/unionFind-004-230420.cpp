//LEVEL 33-3
//인접행렬 cycle 찾기

#include <iostream>
#include <vector>
using namespace std;

int vect[200];

int find(int x) {
	if (vect[x] == 0)return x;
	int ret = find(vect[x]);
	vect[x] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B)return;
	vect[B] = A;
	return;
}

void init(int n, vector<vector<int>>& map) {
	int input;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> input;
			map[y].push_back(input);
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;
	vector<vector <int>> map(n);
	init(n, map);

	for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (map[y][x] == 1) {
				if (find(y) == find(x)) {
					cout << "cycle 발견";
					return 0;
				}
				setUnion(y, x);
			}
		}
	}
	cout << "미발견";

	return 0;
}