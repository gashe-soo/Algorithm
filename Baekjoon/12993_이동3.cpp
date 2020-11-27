// 백준 12993번 이동

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;

    while (x || y) {
        if (x % 3 + y % 3 != 1) {
            cout << 0;
            return 0;
        }
        x /= 3;
        y /= 3;
    }
    cout << 1;

    return 0;
}