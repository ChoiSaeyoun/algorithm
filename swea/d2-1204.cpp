#include<iostream>
#include<string>
using namespace std;

int dat[101];
int input, maxi;

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
		memset(dat, 0, 101 * sizeof(int));
		maxi = 0;

		cin >> test_case;
		for (int i = 0; i < 1000; i++) {
			cin >> input;
			dat[input]++;
		}
		for (int i = 0; i <= 100; i++) {
			if (dat[maxi] <= dat[i])maxi = i;
		}
		cout << "#" << test_case << " " << maxi << "\n";
	}
	return 0;
}