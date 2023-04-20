//LEVEL 33-1
//Cycle을 찾아라

#include <iostream>
using namespace std;

int boss[200];

int find(int x) {
	if (boss[x] == 0)return x;
	int ret = find(boss[x]);
	boss[x] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B)return;
	boss[B] = A;
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, flag = 0;
	char a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (find(a) == find(b))flag = 1;
		setUnion(a, b);
	}
	if (flag == 1)cout << "발견";
	else cout << "미발견";

	return 0;
}