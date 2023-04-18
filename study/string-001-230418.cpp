//민코딩 검색엔진

//6개의 단어 하드코딩
//입력 : 네 글자의 검색어 (ex. ??B?)
//출력 : 해당하는 단어의 개수

#include <iostream>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string arr[6] = { "ABCD","ABCE","AGEH","EIEI","FEQE","ABAD" };
	string input;
	int cnt = 0;

	cin >> input;

	for (int i = 0; i < 6; i++) {
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (input[j] != '?') {
				if (arr[i][j] != input[j]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)cnt++;
	}

	cout << cnt;
}