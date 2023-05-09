#include<iostream>
#include<algorithm>
using namespace std;

int n, gap;
int arr[100];
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + 100, greater<int>());

		while (n > 0) {
			arr[0]--;
			arr[99]++;
			n--;

			sort(arr, arr + 100, greater<int>());
			gap = arr[0] - arr[99];
			if (gap <= 1) {
				break;
			}
		}

		cout << "#" << test_case << " " << gap << "\n";
	}
	return 0;
}