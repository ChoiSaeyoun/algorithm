//이름 정렬하기

//문자열 개수 N값과 N명의 이름 입력
//1. 길이 순 2. 사전 순 (오름차순) 으로 정렬하여 출력

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a, string b) {
	if (a.length() < b.length())return 1;
	if (a.length() > b.length())return 0;

	return a < b;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	vector<string> nameList;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		nameList.push_back(input);
	}

	sort(nameList.begin(), nameList.end(), compare);

	for (int i = 0; i < nameList.size(); i++) {
		cout << nameList[i] << "\n";
	}
}