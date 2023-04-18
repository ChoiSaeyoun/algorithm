#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    //freopen_s(new FILE*, "input.txt", "r", stdin);

    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, cnt;
        int arr[1000] = {};

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < N; i++) {
            int max1 = 0, max2 = 0;
            if (i <= 1 || i >= N - 2)continue;
            for (int j = i - 2; j <= i + 2; j++) {
                if (arr[j] > arr[max1]) {
                    max2 = max1;
                    max1 = j;
                }
                else if (arr[j] > arr[max2]) {
                    max2 = j;
                }
            }
            if (max1 == i)cnt += arr[max1] - arr[max2];
        }
        cout << "#" << test_case << " " << cnt << "\n";

    }

    return 0;
}