//level 42-3
//°¡¼ö BTS¿Í SES

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string target;
string words[5] = { "BTS","SBS","BS","CBS","SES" };
string path;
int minLevel = 21e8;
void run(int level, string path) {
	if (path.length() > target.length())return;
	if (path == target) {
		minLevel = min(minLevel, level);
		return;
	}
	for (int i = 0; i < 5; i++) {
		run(level + 1, path + words[i]);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> target;
	run(0, "");
	cout << minLevel;

	return 0;
}