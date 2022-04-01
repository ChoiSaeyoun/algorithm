#include <iostream>
using namespace std;

int vect[3][5] = {
	1,2,3,4,1,
	3,1,0,0,1,
	2,3,4,1,2
};
int pattern[3] = { 3,4,1 };

//dy, dx를 시작으로 패턴이 존재하는지 조사
int isPattern(int dy, int dx) {
	for (int x = 0; x < 3; x++) {
		if (pattern[x] != vect[dy][dx + x])return 0;
	}
	return 1;
}

int main() {
	int result;

//패턴이 있는지 조사 (x는 vect길이-pattern길이 까지만 조사)
	for (int y = 0; y<3; y++) {
		for (int x = 0; x <= 2; x++) {
			if (isPattern(y, x) == 1) {
				cout << y << "," << x << endl;
			}
		}
	}


	return 0;
}
