//알파벳 카드 선정

//입력 : 대문자 알파벳 문자열, 뽑을 카드 수 N
//출력 : 문자열을 사전순으로 나열했을 때, 가장 뒤에 있는 N장의 카드 중 빈도수가 높은 문자
//(동률이라면, 사전상 앞에 있는 문자)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;
	string tar;
	int N;
	int dat[200] = {};
	int maxI = 0;

	cin >> str >> N;

	sort(str.begin(), str.end());
	tar = str.substr(str.length() - N + 1, N);

	for (int i = 0; i < tar.length(); i++) {
		dat[tar[i]]++;
		if (dat[tar[i]] > dat[tar[maxI]])maxI = i;
	}

	cout << tar[maxI];
}