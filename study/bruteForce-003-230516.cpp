//level 42-1
//±Ëπ‰ º”¿Á∑·

#include<iostream>
#include<cstring>
using namespace std;

string input;
char path[3];

void run(int level, int start) {
	if (level == 3) {
		cout << path << "\n";
		return;
	}
	for (int i = start; i < input.length(); i++) {
		path[level] = input[i];
		run(level + 1, i);
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> input;
	run(0, 0);

	return 0;
}