#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;

typedef long long ll;
const int MAX = 100000;
int map[MAX + 1];

void genMap() {
	int maxDiv = 2;
	for (int num = 1; num <= MAX; num++) {
		for (int div = maxDiv; div >= 1; div--) {
			if (num % div == 0) {
				map[num] = abs(num / div - div);
				if (map[num] == 0)maxDiv = div + 1;
				break;
			}
		}
	}
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

	genMap();

	int N, A, B;
	int M;
	ll res;
	ll minRes;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> A >> B;
		M = N;
		minRes = LLONG_MAX;
		while (M >= 1) {
			res = (ll)A * map[M] + (ll)B * (N - M);
			if (res < minRes)minRes = res;
			if (map[M] == 0)break;
			M--;
		}
		cout << "#" << test_case << " " << minRes << "\n";
	}
	return 0;
}