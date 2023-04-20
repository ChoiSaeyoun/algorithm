//LEVEL 33-1
//Cycle�� ã�ƶ�

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
	if (flag == 1)cout << "�߰�";
	else cout << "�̹߰�";

	return 0;
}