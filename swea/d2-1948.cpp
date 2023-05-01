#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int m1, d1, m2, d2, sum = 0;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        cin >> m1 >> d1 >> m2 >> d2;
        sum = 0;
        if (m1 == m2) {
            sum = d2 - d1 + 1;
        }
        else {
            sum += arr[m1] - d1 + 1 + d2;
            for (int i = m1 + 1; i <= m2 - 1; i++) {
                sum += arr[i];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}