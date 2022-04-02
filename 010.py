#include <iostream>
using namespace std;

int map[5][5] = {
	3, 3, 5, 3, 1,
	2, 2, 4, 2, 6,
	4, 9, 2, 3, 4,
	1, 1, 1, 1, 1,
	3, 3, 5, 9, 2,
};

//상하좌우 합 구하기
int sum(int y, int x)
{
	int direct[4][2] = {
		-1,0,
		0,-1,
		0,1,
		1,0,
	};
	int dy, dx, t;

	int sum = 0;
	for (t = 0; t < 4; t++)
	{
		dy = y + direct[t][0]; //offset을 적용한 y값
		dx = x + direct[t][1]; //offset을 적용한 x값
		if ( dy < 0 || dy>4 || dx < 0 || dx>4) continue; //예외처리
		sum += map[dy][dx]; //합하기
	}
	return sum;
}

int main()
{
	int x, y;
	int max = -999;
	int maxY, maxX;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			int ret = sum(y, x);

			if (ret > max)
			{
				max = ret;
				maxY = y;
				maxX = x;
			}
		}
	}

	cout << maxY << " " << maxX;

	return 0;
}
