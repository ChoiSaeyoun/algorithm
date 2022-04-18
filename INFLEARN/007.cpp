#include <iostream>
using namespace std;

char str[6] = "GHOST";
char input[10];

//index를 시작으로 패턴이 있는지 조사
int isPattern(int index) {
	for (int i = 0; i < 5; i++) {
		if (str[i] != input[index + i])return 0;
	}
	return 1;
}

int main() {
	int len = 0, flag = 0;
	cin >> input;

//input 길이 구하기
	for (int i = 0; i < 10; i++) {
		if (str[i] == '\0') {
			len = i;
			break;//☝까먹지 말기
		}
	}

//0부터 (input길이-str길이)까지만 패턴이 있는지 조사
	for (int i = 0; i < len-4; i++) {
		if (isPattern(i) == 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)cout << "존재";
	else cout << "존재하지 않음";

	return 0;
}
