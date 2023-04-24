//LEVEL 34-4
//클라우드 데이터 백업

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findRow(vector<string> arr) {
	int size = arr[0].length();
	int start = 0, end = size - 1, mid = 0, max = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid][size - 1] == '0')end = mid - 1;
		else {
			start = mid + 1;
			if (max < mid)max = mid;
		}
	}
	return max + 1;
}
int findColumn(vector<string> arr, int row) {
	int size = arr[0].length();
	int start = 0, end = size - 1, mid = 0, max = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[row][mid] == '0')end = mid - 1;
		else {
			start = mid + 1;
			if (max < mid)max = mid;
		}
	}
	return max;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int row = findRow(arr);
	int column = findColumn(arr, row);

	cout << row << " " << column;
}