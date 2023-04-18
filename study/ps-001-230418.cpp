//���Ѳ� ��ȣ ���߱�

//1~50 �� ���� ���� �����ϱ�
//�Է� : ��Ʈ�� ���� N, (����, UP or DOWN) ������ �̷���� ��Ʈ
//��� : ������ ������ ���� or ERROR or ���� ����

#include <iostream>
#include <vector>
using namespace std;

struct Hint {
	int num;
	string dir;
};
int N;
vector<Hint> hints;

void init() {
	int n;
	string d;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> d;
		hints.push_back({ n,d });
	}

	return;
}

int guess(int* min, int* max) {
	for (int i = 0; i < N; i++) {
		Hint tar = hints[i];
		if (tar.dir == "DOWN") {
			if (tar.num <= *min) return -1;
			else *max = tar.num - 1;
		}
		else {
			if (tar.num >= *max)return -1;
			else *min = tar.num + 1;
		}
	}
	if (*min == *max)return 1;
	return 0;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int min = 1, max = 50, res;
	init();
	res = guess(&min, &max);

	if (res == -1)cout << "ERROR";
	else if (res == 0)cout << min << " ~ " << max;
	else cout << min;

}