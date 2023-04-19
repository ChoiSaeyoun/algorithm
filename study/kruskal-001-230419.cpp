//입력 : 문자 2개와 가중치값의 세트
//A B 3
//A C 5
//B C 2
//B D 1
//A D 15
//C D 2
//E D 3
//E C 6
// 
//출력 : (상하좌우가 맞닿은 섬은 하나의 섬으로 간주) 좌표가 입력될 때마다의 섬의 개수 
//1 1 2 2 3 3 1

#include <iostream>
using namespace std;

int boss[200];
struct Node {
	char a, b;
	int price;
};
Node list[100];

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
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n = 8;
	for (int i = 0; i < n; i++) {
		Node temp;
		cin >> temp.a >> temp.b >> temp.price;
		list[i] = temp;
	}

	//1.sort
	for (int y = 0; y < n; y++) {
		for (int x = y + 1; x < n; x++) {
			if (list[y].price > list[x].price)
				swap(list[y], list[x]);
		}
	}

	//2.탐색
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a = list[i].a;
		int b = list[i].b;
		int price = list[i].price;

		if (find(a) == find(b)) continue;
		setUnion(a, b);

		cnt++;
		sum += price;

		if (cnt == 4)break;
	}
	cout << sum;
}