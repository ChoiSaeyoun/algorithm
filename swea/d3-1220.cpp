#include<iostream>
using namespace std;

int input[100][100];

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, now, flag = 0, cnt = 0;
		cin >> n;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> input[y][x];
			}
		}

		for (int x = 0; x < n; x++) {
			flag = 0;
			for (int y = 0; y < n; y++) {
				now = input[y][x];
				if (now == 0)continue;
				if (now == 1)flag = 1;
				if (now == 2) {
					if (flag == 1) {
						cnt++;
						flag = 0;
					}
					else continue;
				}
			}
		}

		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}