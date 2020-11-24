// 백준 19949번 영재의 시험

#include <iostream>

using namespace std;

int ans[10];
int answer;
int p[10];

void solve(int idx)
{
    if (idx == 10) {
        int val = 0;
        for (int i = 0; i < 10; i++) {
            if (ans[i] == p[i]) {
                val++;
            }
        }
        if (val >= 5)
            answer++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        p[idx] = i;
        if (idx >= 2 && (p[idx - 1] == i) && (p[idx - 2] == i))
            continue;
        solve(idx + 1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++)
        cin >> ans[i];

    solve(0);
    cout << answer;
    return 0;
}