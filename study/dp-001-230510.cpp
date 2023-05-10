//출력 : +1/+2/*2 씩 이동할 때 최대 점수
//출발(index 1) 도착(index 15이상) 

//강사님 방법 : 해당 인덱스에서 -1 -2 /2 값으로 갱신 (뒤에서부터 앞으로 선택)

#include<iostream>
#include<algorithm>
using namespace std;

const int Min = -21e8;
int map[16] = { 0,0,5,10,-30,5,4,-20,-30,-50,40,1,5,4,20,0 };
int sum[16];

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	fill(sum, sum + 16, Min);
	sum[1] = 0;
	int M = 0;
	for (int i = 1; i <= 14; i++) {
		if (i + 1 >= 15)M = max(M, sum[i]);
		else if (sum[i + 1] < sum[i] + map[i + 1])sum[i + 1] = sum[i] + map[i + 1];
		if (i + 2 >= 15)M = max(M, sum[i]);
		else if (sum[i + 2] < sum[i] + map[i + 2])sum[i + 2] = sum[i] + map[i + 2];
		if (i * 2 >= 15)M = max(M, sum[i]);
		else if (sum[i * 2] < sum[i] + map[i * 2])sum[i * 2] = sum[i] + map[i * 2];
	}
	cout << M;
	return 0;
}
