#include <iostream>
using namespace std;

void abc(int level) {
	cout << level;
	if (level == 5)return;
	abc(level + 1);
	cout << level;
}

int main() {
	abc(1);
	return 0;
}
