#include<iostream>
#include<string>
using namespace std;

string toBit(int n) {
    string res = "";
    res.resize(6);
    for (int i = 5; i >= 0; i--) {
        res[i] = n % 2 + '0';
        n /= 2;
    }
    return res;
}
char toChar(string s) {
    int res = 0;
    int k = 1;
    for (int i = 7; i >= 0; i--) {
        res += (s[i] - '0') * k;
        k *= 2;
    }
    return char(res);
}
int toDecode(char ch) {
    if (ch >= 'A' && ch <= 'Z')return ch - 'A';
    if (ch >= 'a' && ch <= 'z')return ch - 'a' + 26;
    if (ch >= '0' && ch <= '9')return ch - '0' + 52;
    if (ch == '+')return 62;
    if (ch == '/')return 63;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        string input, inputAll, output;
        cin >> input;
        int inputL = input.length();
        for (int i = 0; i < inputL; i++) {
            inputAll += toBit(toDecode(input[i]));
        }
        while (inputAll != "") {
            output += toChar(inputAll.substr(0, 8));
            inputAll.erase(0, 8);
        }
        cout << output << "\n";
    }
    return 0;
}