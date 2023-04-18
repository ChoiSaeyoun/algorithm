//병뚜껑 번호 맞추기

//1~50 중 정답 숫자 추측하기
//입력 : 힌트의 개수 N, (숫자, UP or DOWN) 쌍으로 이루어진 힌트
//출력 : 가능한 숫자의 범위 or ERROR or 정답 숫자

#include <iostream>
#include <vector>
using namespace std;

struct Hint {
	int num;
	string dir;
};
int N;
vector<Hint> hints;

void init() {
	int n;
	string d;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> d;
		hints.push_back({ n,d });
	}

	return;
}

int guess(int* min, int* max) {
	for (int i = 0; i < N; i++) {
		Hint tar = hints[i];
		if (tar.dir == "DOWN") {
			if (tar.num <= *min) return -1;
			else *max = tar.num - 1;
		}
		else {
			if (tar.num >= *max)return -1;
			else *min = tar.num + 1;
		}
	}
	if (*min == *max)return 1;
	return 0;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int min = 1, max = 50, res;
	init();
	res = guess(&min, &max);

	if (res == -1)cout << "ERROR";
	else if (res == 0)cout << min << " ~ " << max;
	else cout << min;

}