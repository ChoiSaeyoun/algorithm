#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string code[50];
int sy, sx, N, M;
int tarNum, sum, res, ans;
string tarBit;
string bits[10] = { "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" };

void findStart() {
	for (int y = 0; y <= N; y++) {
		for (int x = M - 1; x >= 0; x--) {
			if (code[y][x] == '1') {
				sy = y; sx = x - 55;
				return;
			}
		}
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
		for (int i = 0; i < 50; i++)code[i] = "";
		sum = 0; res = 0;

		cin >> N >> M;
		for (int i = 0; i < N; i++)cin >> code[i];
		findStart();

		for (int i = 0; i < 8; i++) {
			tarBit = code[sy].substr(sx, 7);
			for (int j = 0; j < 10; j++) {
				if (bits[j] == tarBit) { tarNum = j; break; }
			}
			if (i % 2 == 0)sum += (tarNum * 3);
			else sum += tarNum;
			res += tarNum;
			sx += 7;
		}

		if (sum % 10 == 0)ans = res;
		else ans = 0;

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}