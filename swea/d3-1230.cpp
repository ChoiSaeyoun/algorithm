#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> codes;
int N, M;
int code;
char command;
int x, y, s;

void Insert(int x, int s) {
	codes.insert(codes.begin() + x, s);
}
void Erase(int x, int y) {
	codes.erase(codes.begin() + x, codes.begin() + x + y);
}
int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		codes.resize(0);
		cout << "#" << test_case << " ";
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> code;
			codes.push_back(code);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> command;
			if (command == 'I') {
				cin >> x >> y;
				for (int j = 0; j < y; j++) {
					cin >> s;
					Insert(x + j, s);
				}
			}
			else if (command == 'D') {
				cin >> x >> y;
				Erase(x, y);
			}
			else {
				cin >> y;
				for (int j = 0; j < y; j++) {
					cin >> s;
					codes.push_back(s);
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			cout << codes[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}