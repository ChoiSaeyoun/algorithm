//level 42-6
//´ÙºóÄ¡ ¹ÎÄÚµå

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int minGop = 21e8;
vector<int>nums;
vector<int>path;
vector<int>minPath;
vector<int>used;

void run(int level, int gop, int start) {
	if (level == M) {
		if (gop < minGop) {
			minGop = gop;
			copy(path.begin(), path.end(), minPath.begin());
		}
		return;
	}
	for (int i = start; i < N; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		path[level] = nums[i];
		run(level + 1, gop * nums[i], i + 1);
		used[i] = 0;
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	used.resize(N, 0);
	path.resize(M);
	minPath.resize(M);
	run(0, 1, 0);
	sort(minPath.begin(), minPath.end());
	for (int i = 0; i < minPath.size(); i++)cout << minPath[i] << " ";

	return 0;
}