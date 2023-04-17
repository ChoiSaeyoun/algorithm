//음료수 창고정리

//총 5개의 line에 0~9사이의 번호들 입력
//정렬할 line 2개를 입력받아 오름차순 정렬
//각 line 별 가장 아래에 있는 번호 5개 출력

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;
int lineNum[2];

int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 5; i++) {
		string input;
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < 2; i++)cin >> lineNum[i];

	for (int i = 0; i < 2; i++) {
		string target = arr[lineNum[i]];
		sort(target.begin(), target.end());
		arr[lineNum[i]] = target;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i][0] << " ";
	}

}