#include<iostream>
#include<queue>
using namespace std;

queue<int> codes;

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
		int num = 1;
		int code;

		cin >> test_case;
		for (int i = 0; i < 8; i++) {
			cin >> code;
			codes.push(code);
		}

		while (1) {
			int newCode = codes.front() - num;
			codes.pop();

			if (newCode <= 0) {
				codes.push(0);
				break;
			}
			codes.push(newCode);

			num++;
			if (num > 5)num = 1;
		}

		cout << "#" << test_case << " ";
		while (!codes.empty()) {
			cout << codes.front() << " ";
			codes.pop();
		}
		cout << "\n";
	}
	return 0;
}