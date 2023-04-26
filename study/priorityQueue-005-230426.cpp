//LEVEL 35-5
//Ugly Number

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int target;
	int index;
};
priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> numbers;
priority_queue<Node> targets;
bool operator<(Node b, Node a) {
	return a.target < b.target;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, target, cnt;
	cin >> n;
	vector<int> result(n);

	for (int i = 0; i < n; i++) {
		cin >> target;
		targets.push({ target,i });
	}

	cnt = 1;
	numbers.push(1);
	unsigned int past = -1;
	while (!targets.empty()) {
		unsigned int number = numbers.top(); numbers.pop();
		if (past == number)continue;

		while (cnt == targets.top().target) {
			result[targets.top().index] = number;
			targets.pop();
			if (targets.empty())break;
		}

		numbers.push(number * 2);
		numbers.push(number * 3);
		numbers.push(number * 5);
		past = number;
		cnt++;
	}

	for (int i = 0; i < n; i++)cout << result[i] << " ";

	return 0;
}