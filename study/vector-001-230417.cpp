//국회의원 투표

//m명의 국민들이 n(1<=n<=100)명의 국회의원들을 투표
//m,n값과 m개의 투표번호와 국민 이름 쌍을 입력
//당선된 (가장 많은 표 득표 & 동률일 경우 앞선 번호) 국회의원이 받은 국민들 이름 출력

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int m, n;
	cin >> m >> n;
	vector<vector<string>> list(n);

	int inputN;
	string inputName;

	int max = 0;
	int maxI = 0;

	for (int i = 0; i < n; i++) {
		cin >> inputN >> inputName;
		list[inputN].push_back(inputName);
	}

	for (int i = 0; i < m; i++) {
		if (list[i].size() > max) {
			max = list[i].size();
			maxI = i;
		}
	}

	for (int i = 0; i < list[maxI].size(); i++) {
		cout << list[maxI][i] << " ";
	}
}