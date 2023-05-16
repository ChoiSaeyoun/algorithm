#include<iostream>
#include<string>
using namespace std;

int n;
string input;
string target[10] = { "00","11","22","33","44","55","66","77","88","99" };
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
		cout << "#" << test_case << " ";
		cin >> n >> input;

		int start = 0;
		while (start != -1) {
			for (int i = 0; i < 10; i++) {
				start = input.find(target[i]);
				if (start == -1)continue;
				input.erase(start, 2);
				break;
			}
		}
		cout << input << "\n";
	}
	return 0;
}