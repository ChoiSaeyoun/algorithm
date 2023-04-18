//이미지 돌리기

//입력 : N(1<=N<=10), K, N*N 배열의 값(0 or 1)
//출력 : K번 N*N 배열을 돌린 결과

#include <iostream>
#include <vector>
using namespace std;

void init(int* N, int* K, vector<vector<int>>& image) {
	int input;

	cin >> *N >> *K;
	for (int i = 0; i < *N; i++) {
		image.push_back({});
		for (int j = 0; j < *N; j++) {
			cin >> input;
			image[i].push_back(input);
		}
	}
}

void roll(int N, vector<vector<int>>& image) {
	vector<vector<int>> temp(N, vector<int>(N));
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int nx = y;
			int ny = (N - 1) - x;
			temp[nx][ny] = image[x][y];
		}
	}
	image = temp;
}
vector<vector<int>> solve(int N, int K, vector<vector<int>> image) {
	vector<vector<int>> answer;
	for (int i = 0; i < K; i++) {
		roll(N, image);
	}
	answer = image;
	return answer;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, K;
	vector<vector<int>> image;
	vector<vector<int>> answer;
	init(&N, &K, image);
	answer = solve(N, K, image);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}