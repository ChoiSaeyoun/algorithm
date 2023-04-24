//LEVEL 31-7
//복합 사전정렬

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compare(string a, string b) {
	if (a.length() < b.length())return 1;
	if (a.length() > b.length()) return 0;

	return a < b;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), compare);

	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i << "\n";
	}

	return 0;
}