//īī�� ���� 
//https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int n = board.size();
	vector<int> result;
	vector<vector<int>> arr(n);

	//1. ���� ��ȯ�ؼ� arr �����
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0)continue;
			arr[j].push_back(board[i][j]);
		}
	}

	//2. moves ��� �����ϱ�
	for (int i = 0; i < moves.size(); i++) {
		int tar = moves[i] - 1;
		if (arr[tar].size() == 0)continue;

		// 3. tar�� �� ������ ĳ���� ����
		result.push_back(arr[tar][arr[tar].size() - 1]);
		arr[tar].pop_back();

		// 4. result�� ������ ���� ĳ���� ���� ��!
		if (result.size() < 2)continue;
		if (result[result.size() - 1] == result[result.size() - 2]) {
			result.pop_back();
			result.pop_back();
			answer += 2;
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	int ret = solution(board, moves);
	if (ret == 4)cout << "����";
	else cout << "����";
}