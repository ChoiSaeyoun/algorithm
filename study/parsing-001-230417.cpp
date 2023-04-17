//새로운 회원관리 시스템

//이름 규칙에 맞게 변경하기
//1. 첫글자 대문자, 나머지 소문자 -> 그대로
//2. 모두 소문자 -> 첫글자만 대문자로
//3. 대소문자 섞여있음 -> 모두 대문자로

//입력 : N값, N개의 이름
//출력 : 이름 규칙에 맞게 변경된 이름을 사전 순으로 정렬

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int checkFirst(string input) {
	if (input[0] >= 'A' && input[0] <= 'Z')return 1;
	return 0;
}

int checkOthers(string input) {
	for (int i = 1; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') return 0;
	}
	return 1;
}

string changeName(string input) {
	string result = input;
	int a = checkFirst(input);
	int b = checkOthers(input);

	if (a && b) return result;
	if (!a && b) {
		result[0] -= 32; return result;
	}
	for (int i = 0; i < input.size(); i++) {
		if (!(input[i] >= 'A' && input[i] <= 'Z'))result[i] -= 32;
	}
	return result;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<string> names;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> name;
		names.push_back(changeName(name));
	}

	sort(names.begin(), names.end());
	for (auto i = names.begin(); i != names.end(); i++) {
		cout << *i << "\n";
	}
}