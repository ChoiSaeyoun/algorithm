//�Է� : ����
//��� : ������ �����ٰ� (�Ҽ��� ����)

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int bs(int start, int end, int target) {
	int max = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target == mid * mid)return mid;
		if (target < mid * mid)end = mid - 1;
		else {
			start = mid + 1;
			if (mid > max)max = mid;
			//start�� ���� ��(=mid) : target�� mid^2 ���ٴ� ū ��������, mid�� �������� ���ɼ��� �����Ƿ�
		}
	}
	return max;
}
int main() {

	int target;
	cin >> target;

	cout << bs(0, 20, target);

	return 0;
}