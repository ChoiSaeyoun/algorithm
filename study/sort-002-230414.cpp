//사격대회 금은동

//N값과 N명의 선수들의 이름과 점수 차례대로 입력받음 (1<=N<=1000000)
//1,2,3 등의 기록을 순서가 바뀔 때마다 출력 (동점이면 나중에 입력된 선수가 우선)
//최소의 메모리를 사용하는 삽입정렬 이용

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
	string name;
	int score;
};

Person record[10] = {};
vector<vector<string>> result;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p = i;
		if (i > 3)p = 3;
		record[p] = {};
		cin >> record[p].name;
		cin >> record[p].score;

		for (int j = i; j >= 1; j--) {
			if (record[j - 1].score <= record[j].score) {
				swap(record[j - 1], record[j]);
			}
		}

		result.push_back({});
		int t = i;
		if (t > 2)t = 2;
		for (int j = 0; j <= t; j++) {
			result[i].push_back(record[j].name);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}