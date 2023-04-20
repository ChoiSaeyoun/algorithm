//LEVEL 33-2
//원시부족

#include <iostream>
using namespace std;

int boss[200];
int cnt = 4;

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
	boss[B] = a;
	cnt--;
	return;
}

void init() {
	boss['B'] = 'A';
	boss['C'] = 'A';
	boss['E'] = 'D';
	boss['F'] = 'D';
	boss['I'] = 'J';
	boss['H'] = 'G';
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	init();

	int n;
	char a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		setUnion(a, b);
	}

	cout << cnt << "개";

	return 0;
}