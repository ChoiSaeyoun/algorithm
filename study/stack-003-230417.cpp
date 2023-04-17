//분당에 바람이 분당

//3*3사이즈 밭의 1칸마다 내구도를 갖는 여러작물이 심어져 있음
//강풍이 불면, 최상단 작물이 강품의 세기만큼 내구도가 깎임 (음수면 사라짐)
//입력 : 좌표수 N, (y좌표, x좌표, 작물의 내구도들), 강풍횟수 K, 강풍의 세기
//출력 : 남은 작물의 개수

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, K;
	vector<int> board[3][3];

	int y, x;
	string powers;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> y >> x >> powers;
		for (int j = 0; j < powers.length(); j++) {
			board[y][x].push_back(powers[j] - '0');
		}
	}

	cin >> K;
	int wind;
	int cnt = 0;

	for (int n = 0; n < K; n++) {
		cin >> wind;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int bs = board[i][j].size();
				if (bs == 0)continue;

				board[i][j][bs - 1] -= wind;
				if (board[i][j][bs - 1] <= 0) board[i][j].pop_back();

				if (n == K - 1)cnt += board[i][j].size();
			}
		}
	}

	cout << cnt;
}