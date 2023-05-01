#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << "\n";
        vector<vector<char>>arr;
        int N;
        char C;

        int K;
        cin >> N;
        arr.push_back({});
        for (int i = 0; i < N; i++) {
            cin >> C >> K;
            while (K > 0) {
                int row = arr.size() - 1;
                arr[row].push_back(C);
                if (arr[row].size() == 10)arr.push_back({});
                K--;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}