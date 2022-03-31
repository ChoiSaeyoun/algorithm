#include <iostream>
#include <string> //string 클래스 사용하기
using namespace std;

int main() {

	string input;
	char gender;
	int age;

	cin >> input;
	int a = input[0] - '0'; //string : 배열로 접근 가능, char형으로 반환 주의, '0'(=48)을 빼주어 int형으로 변환가능
	int b = input[1] - '0';
	int year = 10 * a + b;

	if (input[7] == '1') {
		gender = 'M';
		age = 2019 - (1900 + year) + 1; //한국나이 : +1
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
	cout << age << " " << gender;

	return 0;
}
