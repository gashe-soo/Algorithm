// 백준 1110번 더하기 사이클

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string k = to_string(n);
    int cnt = 0;
    while (true) {
        cnt++;
        if (k.size() < 2) {
            k = "0" + k;
        }
        int a = k[0] - '0';
        int b = k[1] - '0';

        int c = (a + b) % 10;

        k = to_string(10 * b + c);
        if (stoi(k) == n)
            break;
    }
    cout << cnt;

    return 0;
}