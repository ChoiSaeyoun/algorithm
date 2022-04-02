#include <iostream>
using namespace std;

char str[11];
int bucket[100];

int main() {
	int len;
	cin >> str;

	//길이구하기
	for (int i = 0; i < 11; i++) {
		if (str[i] == '\0') {
			len = i;
			break;//☝까먹지 말기
		}
	}

	//길이 만큼 bucket에 채우기
	for (int i = 0; i < len; i++) {
		bucket[str[i]]++;
	}

	//bucket 탐색하면서 1개 이상 있는 곳 출력하기
	for (int i = 65; i < 100; i++) {
		if (bucket[i] > 0)cout << char(i) << ":" << bucket[i] << endl;
	}

	return 0;
}
