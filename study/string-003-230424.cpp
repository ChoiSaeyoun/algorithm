//LEVEL 31-8
//숫자 부침개

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int go(int n) {
	n *= 2;
	string str = to_string(n);
	string res;
	int j = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		res += str[i];
	}
	return stoi(res);
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		int res = go(a);
		a = res;
	}

	cout << a;

	return 0;
}