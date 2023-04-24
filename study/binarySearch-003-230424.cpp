//LEVEL 34-2
//자동차 기름 채우기

#include <iostream>
#include <string>
using namespace std;

string input;

int bs(int start, int end) {
	int mid = 0, max = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (input[mid] == '_') end = mid - 1;
		else {
			start = mid + 1;
			if (max < mid)max = mid;
		}
	}
	return max;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> input;

	int ret = bs(0, input.length() - 1);
	cout << (ret + 1) * 10 << "%";
}