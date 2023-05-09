//Greedy TOP-2

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, len;
	cin >> n >> len;
	vector<int> holes(n);
	for (int i = 0; i < n; i++)cin >> holes[i];
	sort(holes.begin(), holes.end());

	int now = 1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (now > holes[i])continue;
		now = holes[i] + len;
		cnt++;
	}
	cout << cnt;
	return 0;
}