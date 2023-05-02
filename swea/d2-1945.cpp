#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    int arr[5] = { 2,3,5,7,11 };
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        int result[5] = { 0 };
        int n;
        cin >> n;
        for (int i = 0; i < 5; i++) {
            if (n == 1)break;
            while (n % arr[i] == 0) {
                n /= arr[i];
                result[i]++;
            }
        }
        for (int i = 0; i < 5; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
