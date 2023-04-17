//Bit 복권 번호 추천 프로그램

//입력 : 사이즈 N의 값, N*N개의 0~9사이의 번호(번호판), N*N개의 0 또는 1(비트배열)
//출력 : 비트배열의 1에 해당하는 위치의 번호판의 번호를 우선순위에 맞게 정렬
//(우선순위 : 1. 빈도수가 높은 순 2. 숫자가 작은 순

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dat[20] = {};

int compare(int a, int b) {
	if (dat[a] > dat[b])return 1;
	if (dat[a] < dat[b])return 0;

	return a < b;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<vector<int>> nb(N);
	vector<int> result;
	int num, bit;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			nb[i].push_back(num);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bit;
			if (bit) {
				int tar = nb[i][j];
				result.push_back(tar);
				dat[tar]++;
			}
		}
	}

	sort(result.begin(), result.end(), compare);

	for (auto i = result.begin(); i != result.end(); i++)cout << *i << " ";
}