#include<iostream>

using namespace std;

int P, Q, R, S, W;

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		cin >> P >> Q >> R >> S >> W;

		cout << min(W * P, Q + max(W - R, 0) * S) << "\n";
	}
	return 0;
}