#include<iostream>
using namespace std;

string input;
char target;
int cnt;

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
		target = '1';
		cnt = 0;
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == target) {
				cnt++;
				if (target == '1')target = '0';
				else target = '1';
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}