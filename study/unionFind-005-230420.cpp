//LEVEL 33-4
//Minco 스테이크 하우스

#include <iostream>
using namespace std;

char vect[200];
char find(int x) {
	if (vect[x] == 0)return x;
	int ret = find(vect[x]);
	vect[x] = ret;
	return ret;
}
void setUnion(int a, int b) {
	char A = find(a);
	char B = find(b);
	if (A == B)return;
	if (!(B >= '1' && B <= '9'))vect[A] = B;
	else vect[B] = A;
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, K;
	char a, b;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		setUnion(a, b);
	}

	for (char i = '1'; i < '1' + K; i++) {
		cout << find(i);
	}

	return 0;
}