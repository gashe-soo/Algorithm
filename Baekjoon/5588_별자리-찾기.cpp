// 백준 5588번 별자리 찾기

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
int n, m;
vector<pi> star;
vector<pi> now;
vector<int> v;
pi ret;

void dfs(int cnt, int idx)
{
    if (idx == m - 1) {
        ret.first = now[cnt].first - star[idx].first;
        ret.second = now[cnt].second - star[idx].second;
        cout << ret.first << " " << ret.second;
        exit(0);
    }

    int nx = star[idx + 1].first - star[idx].first;
    int ny = star[idx + 1].second - star[idx].second;

    for (int i = cnt + 1; i < n; i++) {
        int dx = now[i].first - now[cnt].first;
        int dy = now[i].second - now[cnt].second;

        if (dx == nx && dy == ny) {
            dfs(i, idx + 1);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        star.push_back({ x, y });
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        now.push_back({ x, y });
    }
    sort(star.begin(), star.end());
    sort(now.begin(), now.end());
    ret = { 0, 0 };

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }

    return 0;
}