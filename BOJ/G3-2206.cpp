#include <iostream>
#include <cstring>
using namespace std;

string W;
string S;
int wlen;
int slen;
int dat[200];
int temp[200];
int cnt = 0;

int isValid(int i) {
	memcpy(temp, dat, 200 * sizeof(int));
	for (int j = i + wlen - 1; j >= i; j--) {
		if (temp[S[j]] == 0) return j;
		temp[S[j]]--;
	}
	return -1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> wlen >> slen >> W >> S;

	for (int i = 0; i < wlen; i++) {
		dat[W[i]]++;
	}
	for (int i = 0; i <= slen - wlen; i++) {
		int ret = isValid(i);
		if (ret == -1) {
			cnt++;
		}
		else i = ret;
	}
	cout << cnt;
	return 0;
}