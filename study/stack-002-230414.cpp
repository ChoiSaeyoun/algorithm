//숫자폭탄

//N의 값과 N개의 폭탄 번호를 입력
//입력된 순서대로 폭탄을 쌓다가, 같은 숫자 폭탄 연속 3개면 모두 터짐
//최종 남아있는 폭탄들을 오름차순 정렬하여 출력

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> list;
vector<int> input;
int arr[100];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		input.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		list.push_back(input[i]);

		if (i <= 1)continue;
		int tail = list.size() - 1;
		if (list[tail] == list[tail - 1] && list[tail - 1] == list[tail - 2]) {
			list.pop_back();
			list.pop_back();
			list.pop_back();
		}
	}

	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

}