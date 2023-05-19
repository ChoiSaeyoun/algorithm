//level 43-5
//그룹사별 ID정리

#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

unordered_map<char, vector<int>>m;
char name[11] = "AEEAEBCCDA";
int id[10] = { 21,15,6,15,34,32,35,36,14,3 };

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 10; i++) {
		m[name[i]].push_back(id[i]);
	}
	char input;
	cin >> input;
	vector<int> output = m[input];
	for (auto i = output.begin(); i != output.end(); ++i) {
		cout << *i << " ";
	}

	return 0;
}