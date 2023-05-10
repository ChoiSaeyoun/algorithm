#include<iostream>
#include<algorithm>
using namespace std;

int map[100][100];

int rowSum() {
	int sum = 0, max = 0;
	for (int y = 0; y < 100; y++) {
		sum = 0;
		for (int x = 0; x < 100; x++) {
			sum += map[y][x];
		}
		if (sum > max)max = sum;
	}
	return max;
}
int columnSum() {
	int sum = 0, max = 0;
	for (int y = 0; y < 100; y++) {
		sum = 0;
		for (int x = 0; x < 100; x++) {
			sum += map[x][y];
		}
		if (sum > max)max = sum;
	}
	return max;
}
int diagonalSum() {
	int sum1 = 0, sum2 = 0;
	for (int y = 0; y < 100; y++) {
		sum1 += map[y][y];
	}
	for (int y = 0; y < 100; y++) {
		sum2 += map[y][99 - y];
	}
	return max(sum1, sum2);
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> map[y][x];
			}
		}
		cout << "#" << test_case << " ";
		cout << max(max(rowSum(), columnSum()), diagonalSum()) << "\n";
	}
	return 0;
}