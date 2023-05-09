//Greedy TOP-3

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node { int bundle, each; };
bool compareB(Node a, Node b) { return a.bundle < b.bundle; }
bool compareE(Node a, Node b) { return a.each < b.each; }

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;

	vector<Node>mart(M);
	for (int i = 0; i < M; i++) {
		cin >> mart[i].bundle >> mart[i].each;
	}
	sort(mart.begin(), mart.end(), compareB);
	int minB = mart[0].bundle;
	sort(mart.begin(), mart.end(), compareE);
	int minE = mart[0].each;

	int price;
	if (minB < minE * 6) {
		price = min((N / 6) * minB + (N % 6) * minE, (N / 6 + 1) * minB);
	}
	else {
		price = N * minE;
	}

	cout << price;

	return 0;
}