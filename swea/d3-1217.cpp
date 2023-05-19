#include<iostream>
using namespace std;

int oper(int base, int exp, int res) {
	if (exp == 1)return res;
	oper(base, exp - 1, res * base);
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T = 10;
	//cin >> T;

	int base, exp;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case >> base >> exp;
		cout << "#" << test_case << " " << oper(base, exp, base) << "\n";
	}
	return 0;
}