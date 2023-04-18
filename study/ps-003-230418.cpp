//할아버지의 유산

//입력 : 수로 이루어진 4*8 배열
//출력 : 배열에서 0이 아닌 수로 이루어진 직사각형 영역의 총합

#include <iostream>
#include <vector>
using namespace std;

int map[4][8] = { 0 };

int isFill(int by, int bx, int ey, int ex) {
	int sum = 0;
	for (int y = by; y <= ey; y++) {
		for (int x = bx; x <= ex; x++) {
			if (map[y][x] == 0)return -1;
			sum += map[y][x];
		}
	}
	return sum;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int max = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
		}
	}

	for (int by = 0; by < 4; by++) {
		for (int bx = 0; bx < 8; bx++) {
			if (map[by][bx]) {
				for (int ey = by; ey < 4; ey++) {
					for (int ex = bx; ex < 8; ex++) {
						if (map[ey][ex]) {
							int res = isFill(by, bx, ey, ex);
							if (res == -1) break;
							if (res > max)max = res;
						}
					}
				}
			}
		}
	}

	cout << max;
}