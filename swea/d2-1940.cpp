#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        int N, cv = 0, o, v, sum = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> o;
            if (o != 0) {
                cin >> v;
                if (o == 1)cv += v;
                else if (o == 2) {
                    cv -= v;
                    if (cv < 0)cv = 0;
                }
            }
            sum += cv;
        }
        cout << sum << "\n";
    }
    return 0;
}
