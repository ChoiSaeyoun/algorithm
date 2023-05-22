#include<iostream>
#include<unordered_map>
using namespace std;

int cnt = 0;
int N;
int usedX[100];
int usedPlus[100];
int usedMinus[100];
void run(int ny) {
	if (ny == N) {
		cnt++; return;
	}
	for (int nx = 0; nx < N; nx++) {
		if (usedX[nx] == 1)continue;
		if (usedPlus[ny + nx] == 1)continue;
		if (usedMinus[ny - nx + 50] == 1)continue;
		usedX[nx] = 1;
		usedPlus[ny + nx] = 1;
		usedMinus[ny - nx + 50] = 1;
		run(ny + 1);
		usedX[nx] = 0;
		usedPlus[ny + nx] = 0;
		usedMinus[ny - nx + 50] = 0;
	}
}

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cnt = 0;
		cin >> N;
		run(0);
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}