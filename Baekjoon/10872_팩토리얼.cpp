// 백준 10872번 팩토리얼

#include <iostream>

using namespace std;

int n;

int fac(int x)
{
    if (x <= 1)
        return 1;
    return x * fac(x - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    cout << fac(n);
    return 0;
}