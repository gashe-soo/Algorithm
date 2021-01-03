// 백준 17831번 대기업-승범이네

/*
해설 참고해서 풀이 완료
트리 dp
*/

#include <cstring>
#include <iostream>
#include <vector>
#define MAX 200001

using namespace std;

int n, dp[MAX][2], skill[MAX];
vector<int> child[MAX];

int solve(int idx, int v)
{
    int& ret = dp[idx][v];
    if (ret != -1)
        return ret;

    ret = 0;

    int a = 0;
    for (int c : child[idx]) {
        a += solve(c, 0);
    }
    if (v) {
        ret = a;
    } else {
        ret = max(ret, a);
        for (int c : child[idx]) {
            int val = a - solve(c, 0) + solve(c, 1) + skill[idx] * skill[c];
            ret = max(ret, val);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int p;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        child[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> skill[i];
    }

    cout << solve(1, 0);
    return 0;
}