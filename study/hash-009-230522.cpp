//level 44-1
//초대받지 못한 손님

#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

unordered_multimap<string, int>m;
int N, age;
string name, spy;
vector<int>spys;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> age;
		if (m.count(name) == 1)spy = name;
		m.insert({ name,age });
	}
	cout << spy << "\n";
	auto mi = m.equal_range(spy);
	for (auto i = mi.first; i != mi.second; ++i) {
		spys.push_back(i->second);
	}
	sort(spys.begin(), spys.end());
	for (auto i = spys.begin(); i != spys.end(); ++i) {
		cout << *i << " ";
	}
	return 0;
}