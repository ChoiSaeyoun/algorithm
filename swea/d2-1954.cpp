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

        int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
        int N, y = 0, x = 0, cnt = 0, i = 0;
        cin >> N;
        vector<vector<int>>map(N, vector<int>(N, -1));
        map[y][x] = ++cnt;

        while (cnt < N * N) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) { i++; i %= 4; continue; }
            if (map[ny][nx] != -1) { i++; i %= 4; continue; }
            map[ny][nx] = ++cnt;
            y = ny;
            x = nx;
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cout << map[y][x] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}