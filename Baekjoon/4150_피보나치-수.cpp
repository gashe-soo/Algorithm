// 백준 4150번 피보나치 수

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string sum(string x, string y)
{
    int num;
    int carry = 0;
    string result;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while (x.length() < y.length()) {
        x += '0';
    }
    while (x.length() > y.length()) {
        y += '0';
    }

    for (int i = 0; i < x.length(); ++i) {
        num = (x[i] - '0' + y[i] - '0' + carry) % 10;
        result += to_string(num);
        carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
    }
    if (carry != 0) {
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    if (n <= 2) {
        cout << 1;
        return 0;
    }

    string a = "1";
    string b = "1";
    string c;

    while (n > 2) {
        c = sum(a, b);
        a = b;
        b = c;
        n--;
    }
    cout << c;
    return 0;
}