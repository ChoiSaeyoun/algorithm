#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	freopen("input.txt", "rt", stdin);
	char input[50], output[50] = { 0 };
	int j = 0, result = 0, mul = 1, cnt=0;
	scanf("%s", input);

	for (int i = 0; input[i]!='\0'; i++){
		if (input[i] >= '0' && input[i] <= '9') {
			result = result * 10 + input[i] - '0';
		}
	}

	for (int i = 1; i <= result; i++) {
		if (result % i == 0) {
			cnt++;
		}
	}
	printf("%d\n%d", result, cnt);

	return 0;
}
