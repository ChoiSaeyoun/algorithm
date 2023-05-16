//level 42-7
//±∏∏≈∆¿ ∞·¿Á

#include<iostream>
using namespace std;

int price[8] = { 15,20,44,22,55,16,45 };
int n;
string orders;
int m;
int MAX = -21e8;

void run(int level, int sum, int start) {
	if (level == m) {
		if (sum % 10 == 0) {
			if (MAX < sum)MAX = sum;
		}
		return;
	}
	for (int i = start; i < orders.length(); i++) {
		run(level + 1, sum + price[orders[i] - 'a'], i + 1);
	}
}
int main()
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> orders >> n;
	m = orders.length() - n;

	run(0, 0, 0);
	cout << MAX;

	return 0;
}