#include<iostream>
#include<cstdlib>
using namespace std;

int N, num, mini, cnt;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        cin >> N;
        mini = 100000; cnt = 0;
        for (int i = 0; i < N; i++) {
            cin >> num;
            int anum = abs(num);
            if (mini > anum) { mini = anum; cnt = 1; }
            else if (mini == anum) cnt++;
        }
        cout << mini << " " << cnt << "\n";
    }
    return 0;
}