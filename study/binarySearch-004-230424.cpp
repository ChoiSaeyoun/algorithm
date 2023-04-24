//LEVEL 34-3
//¹ÎÄÚ ºÏÄ«Æä

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bs(int start, int end, string target, vector<string> books, int s) {
	int mid = 0, cnt = 0;
	while (start <= end) {
		if (cnt >= s)return 0;
		mid = (start + end) / 2;
		if (books[mid] == target)return 1;
		if (books[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		cnt++;
	}
	return 0;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, m;

	cin >> n;
	vector<string> books(n);
	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}
	sort(books.begin(), books.end());

	cin >> m;
	string book;
	int s;
	for (int i = 0; i < m; i++) {
		cin >> book >> s;
		if (bs(0, n - 1, book, books, s)) cout << "pass\n";
		else cout << "fail\n";
	}
}