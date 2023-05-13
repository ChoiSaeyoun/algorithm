//level 41-5

#include<iostream>
using namespace std;

string output;
char input[3];
int used[3];
void run(int level) {
	if (level == 3) {
		cout << output << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		output[level] = input[i];
		run(level + 1);
		used[i] = 0;
	}
}
int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	output.resize(3);
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}
	run(0);

	return 0;
}