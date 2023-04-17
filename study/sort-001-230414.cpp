//구조체 삽입정렬
// 
//숫자와 문자가 한 쌍인 n개 Set을 구조체 배열에 입력 (1 <= n <= 100)
//아래 우선순위에 맞춰 삽입정렬로 정렬 후 출력
//1. 더 작은 숫자 우선
//2. 더 작은 문자 우선

#include <iostream>
#include <vector>
using namespace std;

struct Set {
	int num;
	int ch;
};

int compare(Set a, Set b) {
	if (a.num < b.num)return 1;
	if (a.num > b.num)return 0;

	if (a.ch < b.ch)return 1;
	return 0;
}

int main() {
	int n;
	vector<Set> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		char b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 1; j--) {
			if (!compare(arr[j - 1], arr[j])) {
				swap(arr[j - 1], arr[j]);
			}
			else break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i].num << " " << (char)arr[i].ch << "\n";
	}
}