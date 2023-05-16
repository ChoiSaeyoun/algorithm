#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, inputSize, flag, cnt = 0, dfsCnt = 0;
string input, path, ans;
void dfs(int now, int cnt) {
	if (cnt == n || now == inputSize - 1) {
		if (path > ans) { ans = path; dfsCnt = cnt; }
		return;
	}
	for (int next = now + 1; next < inputSize; next++) {
		string backup = path;
		if (path[now] == path[next])flag = 1;
		if (path[next] > path[now]) {
			char temp = path[now];
			path[now] = path[next];
			path[next] = temp;
			dfs(now + 1, cnt + 1);
		}
		else if (next == inputSize - 1) {
			dfs(now + 1, cnt);
		}
		path = backup;
	}
	return;
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
		cout << "#" << test_case << " ";
		cin >> input >> n;
		inputSize = input.length();
		path = input;
		flag = 0;
		ans = "";

		dfs(0, 0);
		string ans2 = ans;
		char temp = ans2[inputSize - 1];
		ans2[inputSize - 1] = ans2[inputSize - 2];
		ans2[inputSize - 2] = temp;

		if ((n - dfsCnt) % 2 == 1) {
			if (flag == 0) {
				ans = ans2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}