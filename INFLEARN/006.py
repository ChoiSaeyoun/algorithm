#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //c++:<string> vs c:<string.h>

int main() {

	char input[50], output[50] = { 0 }; //문자배열 0으로 초기화
	int j = 0, result = 0, mul = 1, cnt=0;
	scanf("%s", input);//C언어의 모든 문자열 끝에는 NULL 문자 (='\0') 자동 삽입
	//문자배열 : 마지막에 NULL 문자가 없는 배열 의미
	//문자열 : 포인터/배열은 변수 자체가 주소 -> & 안써도 무방
	//"%s" : 띄어쓰기 주의
	int len = strlen(input); //'\0'값이 나오기 전까지의 길이 출력

	for (int i = 0; i < len; i++){
		if (input[i] >= '0' && input[i] <= '9') {
			output[j++] = input[i]; //j번 인덱스에 입력 후, 증감연산자 진행
		}
	}
	for (int i = --j; i >=0; i--) {
		result += (output[i]-'0')*mul; //char형 int형 헷갈림 주의
		mul *= 10;
	}
	for (int i = 1; i <= result; i++) {
		if (result % i == 0) {
			cnt++;
		}
	}
	printf("%d\n%d", result, cnt);

	return 0;
}
