#define _CRT_SECURE_NO_WARNINGS //freopen, scanf 안전상 오류 무시하기 위함
#include <stdio.h

int main() {

	freopen("input.txt", "rt", stdin);

	char input[20];
	char gender;
	int age;

	scanf("%s", &input); //scanf는 string문자열 입력받지 못함->char문자열로 입력받기 (%s)
	int a = input[0] - '0';
	int b = input[1] - '0';
	int year = 10 * a + b;

	if (input[7] == '1') {
		gender = 'M';
		age = 2019 - (1900 + year) + 1;
	}
	else if (input[7] == '2') {
		gender = 'W';
		age = 2019 - (1900 + year) + 1;
	}
	else if (input[7] == '3') {
		gender = 'M';
		age = 2019 - (2000 + year) + 1;
	}
	else {
		gender = 'W';
		age = 2019 - (2000 + year) + 1;
	}
	printf("%d %c", age, gender);

	return 0;
}
