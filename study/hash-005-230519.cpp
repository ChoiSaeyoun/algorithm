//level 43-4
//공룡들의 나이 정리

#include <iostream>
#include <unordered_map>

typedef long long ll;
using namespace std;

unordered_map<int, string>m;
ll ages[8] = { 1000000005,1000000002,1000000003,1000000006,1000000015,1000000022,1000000013 };
string names[8] = { "Sour","Dav","Nica","Timer","Pico","Topisl","Whab" };

int hashFunc(ll key) {
	return key % 100;
}
void push(ll key, string value) {
	m[hashFunc(key)] = value;
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 8; i++) {
		push(ages[i], names[i]);
	}

	ll input;
	cin >> input;
	cout << m[input % 100];

	return 0;
}