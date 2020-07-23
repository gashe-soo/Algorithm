// 백준 3430번 용이 산다



#include<iostream>
#include<set>
#include<algorithm>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int LEN = 1e6 + 1;
int n, m, ans[LEN], a[LEN];

bool go() {
    set<int> s;
    f(i, 1, m) {
        int t; cin >> t;
        if (t == 0) {
            s.insert(i);
            ans[i] = 0;
        }
        else {
            set<int>::iterator it = s.upper_bound(a[t]);
            if (it == s.end()) {
                while (m-- > i)cin >> t;
                return false;
            }

            ans[*it] = t;
            a[t] = i;
            s.erase(it);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int z; cin >> z;
    while (z--) {
        cin >> n >> m;
        f(i, 1, m)a[i] = ans[i] = -1;

        if (go()) {
            cout << "YES\n";
            f(i, 1, m)if (ans[i] != -1)cout << ans[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
    return 0;
}

