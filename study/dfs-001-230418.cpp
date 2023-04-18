//다이하드3

//입력 : 시작번호
//출력 : 시작번호에서 (칸 수, left or right) 이동한 후 
//       목적지에 도착하는 경로의 번호를 역순으로 출력

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
		cout << index << "번\n";
		return;
	}
	if (hint.dir == 'r') run(index + hint.num);
	else run(index - hint.num);
	cout << index << "번\n";
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int startIndex;
	cin >> startIndex;
	run(startIndex);

}