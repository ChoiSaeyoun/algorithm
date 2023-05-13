//level 41-1

#include<iostream>
using namespace std;

int memo[100];
int run(int x) {
	if (memo[x] > 0)return memo[x];
	if (x == 0 || x == 1)return x;
	int a = run(x - 2);
	int b = run(x - 1);
	int ret = a + b;
	memo[x] = ret;
	return ret;
}
int main()
{
	int n;
	cin >> n;

	cout << run(n - 1);

	return 0;
}