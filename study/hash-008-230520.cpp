//초기화 : 알파벳 배열
//입력 : tar 문자열 (2~6글자)
//출력 : tar 문자열의 좌표 (없으면 X)

#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

string map[5] = {
	"ABCDE",
	"FGHIJ",
	"KLMOD",
	"BCDBCD",
	"ABAB"
};
struct Node { int y, x; };
unordered_multimap<string, Node>m;

void init() {
	string s;
	for (int len = 2; len <= 6; len++) {
		for (int y = 0; y < 5; y++) {
			int ylen = map[y].length();
			for (int x = 0; x <= ylen - len; x++) {
				s = map[y].substr(x, len);
				m.insert({ s,{y,x} });
			}
		}
	}
}
int main()
{
	init();
	string tar;
	cin >> tar;

	if (m.count(tar) == 0) {
		cout << "X";
	}
	else {
		auto mi = m.equal_range(tar);
		for (auto i = mi.first; i != mi.second; ++i) {
			cout << i->second.y << " " << i->second.x << "\n";
		}
	}
	return 0;
}