#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, X;
	cin >> N >> X;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < X)cout << arr[i]<<" ";
	}
	
	return 0;
}
