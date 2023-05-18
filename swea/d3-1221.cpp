#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

string s[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
unordered_map<string, int>m;
vector<string>inputs;
string dum;
int len;
string input;

bool compare(string a, string b) {
	return m[a] < m[b];
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int test_case;
	int T;
	cin >> T;

	for (int i = 0; i < 10; i++) {
		m[s[i]] = i;
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> dum >> len;
		inputs.resize(0);

		for (int i = 0; i < len; i++) {
			cin >> input;
			inputs.push_back(input);
		}

		sort(inputs.begin(), inputs.end(), compare);

		cout << "#" << test_case << "\n";
		for (auto i = inputs.begin(); i != inputs.end(); ++i) {
			cout << *i << " ";
		}
		cout << "\n";

	}
	return 0;
}