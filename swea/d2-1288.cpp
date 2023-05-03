#include<iostream>
#include<cstring>
using namespace std;
int dat[10];
int cnt;
void Count(int n) {
    while (n != 0) {
        int t = n % 10;
        if (dat[t] == 0) {
            dat[t] = 1; cnt++;
        }
        n /= 10;
    }
    return;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(dat, 0, 10 * sizeof(int));
        cnt = 0;
        cout << "#" << test_case << " ";
        int n, i = 0;
        cin >> n;
        while (cnt < 10) {
            ++i;
            Count(n * i);
        }
        cout << n * i << "\n";
    }
    return 0;
}