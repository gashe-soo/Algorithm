// 백준 2002번 추월

/*
hashmap 이용해서 순서 확인

시간복잡도 O(n^2)
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
string out[1001];
unordered_map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s] = i;
    }

    for (int i = 0; i < n; i++)
        cin >> out[i];

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[out[i]] > m[out[j]]) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}