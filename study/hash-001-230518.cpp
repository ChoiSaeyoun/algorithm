//�Է� : ���� ���ڿ�, Ÿ�� ���ڿ�(4����)
//��� : Ÿ�� ���ڿ��� ���� ���ڿ��� ���°�� �ִ��� (���� ���̶��, �� �տ� �ִ� ��)

#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

string map = "ABTTRSBCDEABABAAABTTBC";
string tar;
unordered_map<string, int>m;

int main()
{
	string s = map.substr(0, 4);
	for (int i = 0; i < map.length() - 4; ++i) {
		if (m.count(s) == 0)m[s] = i;
		s += map[i + 4];
		s.erase(0, 1);
	}

	cin >> tar;
	cout << m[tar];
	return 0;
}