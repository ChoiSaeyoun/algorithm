//LEVEL 33-5
//춘추 전국 시대

#include <iostream>
#include <vector>
using namespace std;

int vect[8];
int find(int x) {
	if (vect[x] == 0)return x;
	int ret = find(vect[x]);
	vect[x] = ret;
	return ret;
}
void setUnion(int a, int b, vector<int>& people, vector<int>& cnt) {
	int A = find(a);
	int B = find(b);
	if (A == B)return;
	vect[B] = A;
	people[A] += people[B];
	people[B] = 0;
	cnt[A] += cnt[B];
	cnt[B] = 0;
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, S;

	cin >> N;
	vector<int> people(N + 1);
	vector<int> cnt(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}
	fill(cnt.begin(), cnt.end(), 1);

	cin >> S;
	string situ;
	char x, y;
	for (int i = 0; i < S; i++) {
		cin >> situ >> x >> y;
		x = x - 'A' + 1;
		y = y - 'A' + 1;
		if (situ == "alliance") {
			setUnion(x, y, people, cnt);
		}
		else {
			int X = find(x);
			int Y = find(y);
			if (people[X] > people[Y]) N -= cnt[Y];
			else N -= cnt[X];
		}
	}

	cout << N;
	return 0;
}