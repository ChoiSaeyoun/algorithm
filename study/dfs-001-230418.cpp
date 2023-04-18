//�����ϵ�3

//�Է� : ���۹�ȣ
//��� : ���۹�ȣ���� (ĭ ��, left or right) �̵��� �� 
//       �������� �����ϴ� ����� ��ȣ�� �������� ���

#include <iostream>
#include <vector>
using namespace std;

struct Hint {
	int num;
	char dir;
};
Hint hints[7] = { {3,'r'},{2,'r'},{1,'l'},{3,'r'},{2,'l'},{-1,'e'},{1,'l'} };

void run(int index) {
	Hint hint = hints[index];
	if (hint.dir == 'e') {
		cout << index << "��\n";
		return;
	}
	if (hint.dir == 'r') run(index + hint.num);
	else run(index - hint.num);
	cout << index << "��\n";
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int startIndex;
	cin >> startIndex;
	run(startIndex);

}