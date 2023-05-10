#include<iostream>
#include<string>
using namespace std;

string t, s;
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case >> t >> s;
		int a = -1, cnt = 0;
		while (1) {
			a = s.find(t, a + 1);
			if (a == -1)break;
			cnt++;
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}