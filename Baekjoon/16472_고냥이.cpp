// 백준 16472번 고냥이

/*
기본적인 컨셉은 투 포인터 + 문자별 위치 확인하기.

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, loc[26], cnt, first, second, ans;
vector<int> now;
string s;

int get(int idx)
{
    return s[idx] - 'a';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    memset(loc, -1, sizeof(loc));
    first = 0, second = 0;
    cnt = 0;
    int size = s.size();

    while (second < size) {
        while (second < size && cnt <= n) {
            int idx = get(second);
            if (loc[idx] == -1) {
                cnt++;
                if (cnt > n)
                    break;
            }
            loc[idx] = second;
            second++;
        }

        if (cnt > n) {
            cnt--;
            ans = max(second - first, ans);

            int fidx = get(first);

            while (get(first) == fidx) {
                first++;
            }

            if (loc[fidx] < first) {
                cnt--;
                loc[fidx] = -1;
            }
        }
    }
    ans = max(ans, second - first);
    cout << ans;
    return 0;
}