//붕어빵 뒤집기

//입력 : 타겟 알파벳들
//출력 : 타겟 알파벳들의 자신 포함 상하좌우가 뒤집힌 (알파벳<->'#') 결과

#include <iostream>
using namespace std;


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string map[3] = { "ABCEFG","HIJKLM","NOPQRS" };
	int back[3][6] = { 0 };
	string targets;
	int dir[5][2] = {
		0,0,
		-1,0,
		1,0,
		0,-1,
		0,1
	};

	cin >> targets;

	int tn = targets.length();
	for (int t = 0; t < tn; t++) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 6; x++) {
				if (map[y][x] == targets[t]) {
					for (int k = 0; k < 5; k++) {
						int nx = x + dir[k][0];
						int ny = y + dir[k][1];
						if (nx < 0 || nx>5 || ny < 0 || ny>2)continue;
						if (back[ny][nx] == 1)back[ny][nx] = 0;
						else back[ny][nx] = 1;
					}
				}
			}
		}
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			if (back[y][x] == 1)cout << "#";
			else cout << map[y][x];
		}
		cout << "\n";
	}
}