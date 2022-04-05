#include <iostream>
using namespace std;

int limitLevel, branch;

void run(int level)
{
	if (level == limitLevel) return;

	for (int x = 0; x < branch; x++)
	{
		run(level + 1);
	}
}

int main()
{
	cin >> limitLevel >> branch;
	run(0);

	return 0;
}
